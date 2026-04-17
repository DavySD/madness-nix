{config, pkgs, ...}: {
  systemd.services.bat-watch = {
  description = "Monitor de bateria para hibernação";
  after = [ "multi-user.target" ];
  wantedBy = [ "multi-user.target" ];
  serviceConfig = {
    Type = "simple";
    Restart = "on-failure";
    RestartSec = "5s";
    ExecStart = pkgs.writeShellScript "bat-watch" ''
      ${pkgs.upower}/bin/upower --monitor | while read -r line; do
        if echo "$line" | grep -q "battery"; then
          BAT=$(${pkgs.upower}/bin/upower -e | grep battery | head -1)
          STATUS=$(${pkgs.upower}/bin/upower -i "$BAT" | awk '/state:/ {print $2}')
          PERCENT=$(${pkgs.upower}/bin/upower -i "$BAT" | awk '/percentage:/ {gsub(/%/,""); print $2}')
          if [[ "$STATUS" == "discharging" && "''${PERCENT%.*}" -le 5 ]]; then
            ${pkgs.util-linux}/bin/logger "bat-watch: ''${PERCENT}%, hibernando"
            systemctl hibernate
          fi
        fi
      done
    '';
  };
};
}
