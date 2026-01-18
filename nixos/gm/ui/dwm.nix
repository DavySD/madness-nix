{config, pkgs, lib, ...}:
{
   services.xserver = {
     autoRepeatInterval = 40;
     autoRepeatDelay = 400;
      windowManager.dwm = {
        enable = true;
        package = pkgs.dwm.overrideAttrs (oldAttrs: {
          src = ./src/dwm;  
          buildInputs = oldAttrs.buildInputs or [] ++ [ pkgs.xorg.libX11 pkgs.xorg.libXft pkgs.xorg.libXinerama ];
        });
    };
};
    environment.systemPackages = with pkgs; [
      (st.overrideAttrs (oldAttrs: {
        src = ./src/st;
      }))
      (dmenu.overrideAttrs (oldAttrs: {
        src = ./src/dmenu;
      }))
      (slstatus.overrideAttrs (oldAttrs: {
        src = ./src/slstatus;
      }))
      picom
      nitrogen
      j4-dmenu-desktop
      maim     
      xset
      xclip
    ];
  
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
    ];
  }; # Nix ld

  services = {
    libinput.enable = true;
  };

}
