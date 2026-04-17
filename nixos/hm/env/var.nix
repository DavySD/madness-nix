{config, ...}:
{
 home.sessionVariables = {
  # QT
  QT_QPA_PLATFORMTHEME = "qt6ct";
  # Other
  NIXOS_OZONE_WL = "1";   
  GSK_RENDERER = "gl";
  LIBVA_DRIVER_NAME = "iHD";
 };
}
