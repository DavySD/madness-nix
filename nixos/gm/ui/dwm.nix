{config, pkgs, lib, ...}:
{
   services.xserver = {
     autoRepeatInterval = 40;
     autoRepeatDelay = 400;
      windowManager.dwm = {
        enable = true;
        package = pkgs.dwm.overrideAttrs (oldAttrs: {
          src = ./src/DWM/dwm;  
          buildInputs = oldAttrs.buildInputs or [] ++ [ pkgs.libX11 pkgs.libXft pkgs.libXinerama ];
        });
    };
};
    environment.systemPackages = with pkgs; [
      (st.overrideAttrs (oldAttrs: {
        src = ./src/DWM/st;
      }))
      (dmenu.overrideAttrs (oldAttrs: {
        src = ./src/DWM/dmenu;
      }))
      (slstatus.overrideAttrs (oldAttrs: {
        src = ./src/DWM/slstatus;
      }))
      picom
      nitrogen
      j4-dmenu-desktop
      maim     
      xset
      xclip
    ];

   # Nix ld
   programs.nix-ld = { 
    enable = true;
    libraries = with pkgs; [
      freetype
      libxrender
      libx11
      libxcb
      libxinerama
      fontconfig
      libxft
      libglvnd
      libxcomposite
      libxcb-keysyms
      libxau
      xauth
    ];
  }; 
  services = {
    libinput.enable = true;
  };

}
