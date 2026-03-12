{ config, pkgs, ...}:
{
 services.pulseaudio.enable = false;
 security.rtkit.enable = true;
 services.pipewire = {
  enable = true;
  pulse.enable = true;
  alsa.enable = true;
  wireplumber.enable = true;
  extraConfig.pipewire."10-clock-rate" = {
    "context.properties" = {
     "default.clock.rate" = 48000;
     "default.clock.quantum" = 2048; # aumenta o buffer
     "default.clock.min-quantum" = 2048;
     "default.clock.max-quantum" = 3048;
      };
    };
  };
}
