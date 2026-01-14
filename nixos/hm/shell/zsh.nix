{config, pkgs, ...}:
{
 programs.zsh = {
  enable = true;
  enableCompletion = true;
  history = {
    size = 5000;
    share = true;
    save = 5000;
    };
  initContent = " export PROMPT='%~ λ ' ";
  shellAliases = {
    nx = "doas nixos-rebuild switch --flake path:/etc/nixos#Cheshire |& nom";
    hm = "home-manager switch --flake path:/etc/nixos#deive@Cheshire |& nom";
    fx = "nix flake update --flake /etc/nixos";
    };
  };

}
