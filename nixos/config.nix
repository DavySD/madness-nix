# ~ λ Madness NixOS
{ config, lib, pkgs, ... }:
{
  imports =
    [ 
      ./gm/hw
      ./hardware-configuration.nix
      ./gm/pkgs
      ./gm/ui/labwc.nix      
      ./gm/fltp/fltp.nix
      ./gm/scy/doas.nix 
      ./gm/powerpills/cpu.nix
      # ./gm/powerpills/overlays # I don't have time to compile :(
    ];

  # Boot
    # Limine
    boot.loader.efi.canTouchEfiVariables = true; 
    boot.loader.limine.enable = true;
    boot.loader.systemd-boot.enable = false;
    boot.loader.grub = { 
	enable = false;
#	device = "nodev";
#	efiSupport = true; 
     };
    # Tmpfs
    boot.tmp.useTmpfs = true;

  # Set kernel.
  boot.kernelPackages = pkgs.linuxPackages_xanmod;
                                                        
  # Network
  networking.hostName = "Cortisol"; 
  networking.wireless.iwd.enable = true;
  networking.wireless.iwd.settings = {Settings = {AutoConnect = true;};};
  services.tailscale.enable = true;
  services.openssh = {
    enable = true;
    settings = {
      PermitRootLogin = "yes";
    };
  };

  # Set time zone.
  time.timeZone = "America/Maceio";

  # X11
  services.xserver = {
    enable = false;
    displayManager.startx.enable = false;
  };

  # Display Manager
  services.displayManager = {
    enable = true;
    ly.enable = true;
    ly.x11Support = true;
  };

  # Locales
  i18n.defaultLocale = "pt_BR.UTF-8";
  i18n.extraLocaleSettings = {
    LC_ADDRESS = "pt_BR.UTF-8";
    LC_IDENTIFICATION = "pt_BR.UTF-8";
    LC_MEASUREMENT = "pt_BR.UTF-8";
    LC_MONETARY = "pt_BR.UTF-8";
    LC_NAME = "pt_BR.UTF-8";
    LC_NUMERIC = "pt_BR.UTF-8";
    LC_PAPER = "pt_BR.UTF-8";
    LC_TELEPHONE = "pt_BR.UTF-8";
    LC_TIME = "pt_BR.UTF-8";
  };

  # Configure keymap in X11
  services.xserver.xkb.layout = "br"; 

  # Configure console keymap
  console.keyMap = "br-abnt2";
 
  # User account 
  users.users.deive = {
    isNormalUser = true;
    description = "deive";
    extraGroups = [ "wheel" "seat" "video" "rtkit" "pipewire" ];
    packages = with pkgs; [ tree ];
  };

  # Shell
  programs.zsh.enable = true;
  users.defaultUserShell = pkgs.zsh;

  # Logind
  services.logind.settings.Login.HandleLidSwitch = "ignore";

  # Security
  security.polkit.enable = true;  
  services.seatd.enable = true;

  # Nix Limit
  nix.settings = {
    max-jobs = 1;
    cores = 1;
    auto-optimise-store = true;
  };

  # System state 
  system.stateVersion = "25.11";
}
