{config, pkgs, ...}: {
  services.flatpak.enable = true;
    xdg.portal = {
      enable = true;
      wlr.enable = true;
      extraPortals = [ pkgs.xdg-desktop-portal pkgs.xdg-desktop-portal-gtk ];
      config.common.default = "*";
      # wlr.settings = {
      #   screencast = {
      #     output_name = "eDP-1";
      #     max_fps = 30;
      #     chooser_type = "simple";
      #     chooser_cmd = "${pkgs.slurp}/bin/slurp -f %o -or";
      #   };
      # };
   };
}
