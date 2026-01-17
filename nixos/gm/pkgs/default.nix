{config, pkgs, ...}:
{
 # Global Packages
 environment.systemPackages = with pkgs; [

  # System
  wget
  mate.mate-polkit
  mesa

  # Audio
  playerctl
  
  # Compile
  clang
  gcc
  cmake
  meson
  ninja
  llvm
  lld

  # Xorg
  xorg.xinit
  libx11
  libxcb
  libxinerama
];

 # Pains
 nix.package = pkgs.lixPackageSets.latest.lix; # Enable Lix
 nix.settings.experimental-features = ["nix-command" "flakes"]; # Enable Flakes.
 nixpkgs.config.allowUnfree = true; # Enable unfree packages
 programs.appimage.enable = true; # Enable Appimages
 programs.appimage.binfmt = true; # ⬆
 programs.xfconf.enable = true; # Enable Xf(ce)conf
 programs.nano.enable = false; # Disable Nano
 programs.gpu-screen-recorder.enable = true; # Enable GSR
 programs.nix-ld = { 
  enable = true;
  libraries = with pkgs; [ ];
  }; # Nix ld

 # Imports
 imports = [ ./extra/thunar.nix ];
}
