{ config, pkgs, ...}:
{
 services.pipewire = {
  enable = true;
  pulse.enable = true;
  alsa.enable = true;
  wireplumber.enable = true;
  extraConfig.pipewire = {
   "10-clock-rate" = {
    "context.properties" = {
     "default.clock.rate" = 48000;
     "default.clock.quantum" = 1024; # aumenta o buffer
     "default.clock.min-quantum" = 1024;
     "default.clock.max-quantum" = 2048;
      };
    };
  };
};

 services.pulseaudio.enable = false;
 security.rtkit.enable = true;

}
