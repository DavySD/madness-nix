{config, pkgs, ...}:
{

 hardware.graphics = {
  enable = true;
   enable32Bit = true;
   extraPackages = with pkgs; [
    intel-media-driver
    vpl-gpu-rt
    intel-vaapi-driver
    ];
  };
 
 environment = {
  systemPackages = with pkgs; [ libva libva-utils ];
  sessionVariables = { LIBVA_DRIVER_NAME = "iHD"; };  
};
 hardware.enableRedistributableFirmware = true;
 boot.kernelParams = [ "i915.enable_guc=3" ];
 }
