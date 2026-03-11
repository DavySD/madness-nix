{ config, pkgs, lib, ... }:
{
  # Home Packages
  home.packages = with pkgs; [

   # Internet
   discord
   uget
   uget-integrator
   
   # Media
   mpv
   strawberry # Music player
   # telegram-desktop
   freetube

   # Utils
   libnotify
   wdisplays
   unrar
   unzip
   peazip
   gammastep # oh, my eyes

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
    
   # Text Editor
   nixd # evil lsp
   nil # good lsp
   helix # badass editor
   geany # graphical editor
   kdePackages.ghostwriter # markdown editor
   vscodium-fhs
   go
   
   # Graphics
   gimp3 # Gnu (is Not Unix) Image Manipulator Program (3)
   inkscape

   # Games
   steam-run
   steam
   hydralauncher 
   libglvnd
   mesa-demos
   libdrm
   lutris
   heroic
   
   # WM things
   fuzzel
   grim
   slurp
   swaybg
   wl-clipboard-rs # Why is there a Rust version of this?
   swappy
   waybar   
   dunst
  ];

  programs.firefox = { enable = true; };
  imports = [ ./extra ./fonts ];
}
