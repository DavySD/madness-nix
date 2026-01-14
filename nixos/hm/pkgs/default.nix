{ config, pkgs, lib, ... }:
{
  # Home Packages
  home.packages = with pkgs; [

   # Media
   pear-desktop
   mpv
   strawberry
   telegram-desktop

   # Utils
   libnotify
   wdisplays
   unrar
   unzip
   peazip

   # Accessories
   ncpamixer
   pavucontrol
   playerctl
   alacritty
   git
   zellij

   # System
   nix-output-monitor
   htop
   btop
    
   # Text Editor
   nixd
   nil
   helix
   geany
   
   # Graphics
   gimp3
   inkscape

   # Games
   steam-run
   steam
   hydralauncher
   libglvnd
   mesa-demos
   libdrm
   
   # WM things
   fuzzel
   grim
   slurp
   swaybg
   wl-clipboard-rs
   swappy
   waybar   
   dunst
  ];

  imports = [ ./extra ./fonts ];
}
