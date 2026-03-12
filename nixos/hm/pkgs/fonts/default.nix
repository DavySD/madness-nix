{config, pkgs, ...}:
{
  fonts.fontconfig.enable = true; 
  home.packages = with pkgs; [
    nerd-fonts.jetbrains-mono
    nerd-fonts.ubuntu-mono
    nerd-fonts.ubuntu
    nerd-fonts.ubuntu-sans
    nerd-fonts.dejavu-sans-mono
    nerd-fonts.fira-code
    nerd-fonts.overpass
    nerd-fonts.victor-mono
    nerd-fonts.symbols-only
    nerd-fonts.fira-code
    nerd-fonts.liberation
    nerd-fonts.hack
    nerd-fonts.droid-sans-mono
    nerd-fonts.adwaita-mono
    nerd-fonts.iosevka
    nerd-fonts.caskaydia-mono
    nerd-fonts.caskaydia-cove
    inter
    noto-fonts
    noto-fonts-color-emoji    
  ];

}
