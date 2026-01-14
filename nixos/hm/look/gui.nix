{config, pkgs, ...}:
{
 home.sessionVariables = {
  QT_QPA_PLATFORMTHEME = "qt6ct";
  };

 home.packages = with pkgs; [
  nwg-look
  kdePackages.qt6ct
  kdePackages.qtstyleplugin-kvantum
 ];

 }
