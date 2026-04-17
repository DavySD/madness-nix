{ config, pkgs, lib, ... }:
{
  # Home Packages
  home.packages = with pkgs; [

   # Internet
   discord
   uget
   uget-integrator
   webcord
   tailscale-systray
   
   # Media
   mpv
   strawberry # Music player
   # telegram-desktop
   freetube
   vlc
   ffmpeg-full
   pear-desktop

   # Office
   libreoffice
   hunspell
   hunspellDicts.pt-br

   # Utils
   libnotify
   wdisplays
   unrar
   unzip
   peazip
   gammastep # oh, my eyes
   s-tui
   stress

   # Accessories
   pavucontrol
   playerctl
   alacritty
   git # normie vcs
   zellij # terminal multiplexer
   zathura

   # System
   nix-output-monitor
   htop
   btop
   upower
    
   # Text Editor
   nixd # evil lsp
   nil # good lsp
   helix # badass editor
   geany # graphical editor
   go
   
   # Graphics
   gimp3 # Gnu (is Not Unix) Image Manipulator Program (3)
   inkscape

   # Games
   steam-run
   # steam
   hydralauncher 
   libglvnd
   mesa-demos
   libdrm
   
   # WM things
   fuzzel
   grim
   slurp
   swaybg
   wl-clipboard-rs # Why is there a Rust version of this?
   swappy
   dunst
   swayidle
   wlopm
  ];

  programs.firefox = { enable = true; };
  imports = [ ./extra ./fonts ];
}
