{config, pkgs, ...}:
{

 hardware.graphics = {
  enable = true;
   enable32Bit = true;
   extraPackages = with pkgs; [
    intel-vaapi-driver
    libva
    ];
  };
 environment = {
  sessionVariables = {LIBVA_DRIVER_NAME = "i965";};  
};
 hardware.enableRedistributableFirmware = true;
 boot.kernelParams = [ ];
 }
