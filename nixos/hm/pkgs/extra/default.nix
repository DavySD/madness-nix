{config, pkgs, lib, ...}:
{
  home.packages = with pkgs; [
   xfce4-panel
   xfce4-pulseaudio-plugin
   xfce4-whiskermenu-plugin
   garcon
   libxfce4util
   libxfce4windowing    
  ]; 

  # Plus
    programs.nh.enable = true;
    programs.nh.flake = "/etc/nixos";
    # imports = [ ./helix.nix ];

}

