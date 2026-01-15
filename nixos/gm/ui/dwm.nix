{config, pkgs, ...}:
{
   services.xserver.windowManager.dwm = {
    enable = true;
    package = pkgs.dwm.overrideAttrs (oldAttrs: {
      src = /home/deive/Modelos/compile/dwm; 
    });
  };
}
