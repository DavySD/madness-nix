{config, pkgs, ...}:
{

 hardware.graphics = {
  enable = true;
   enable32Bit = true;
   extraPackages = with pkgs; [
    intel-media-driver
    libva
    libva-utils
    ];
  };
 environment = {
  sessionVariables = {LIBVA_DRIVER_NAME = "HD";};  
};
 hardware.enableRedistributableFirmware = true;
 boot.kernelParams = [ ];
 }
