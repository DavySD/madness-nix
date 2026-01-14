{config, pkgs, ...}:
{
  imports = [
    ./pipewire.nix
    ./swap.nix
    ./vp.nix
  ];
}
