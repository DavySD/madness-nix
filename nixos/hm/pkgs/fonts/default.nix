{config, pkgs, ...}:
{
  fonts.fontconfig.enable = true; 
  home.packages = with pkgs; [
    nerd-fonts.victor-mono
    nerd-fonts.symbols-only
    nerd-fonts
    inter
    noto-fonts
    noto-fonts-color-emoji    
  ];

}
