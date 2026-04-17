{
  
 description = "~ λ A simple flakes, huh?";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable"; 
    home-manager.url = "github:nix-community/home-manager";
    home-manager.inputs.nixpkgs.follows = "nixpkgs";
  };

  outputs = { self, nixpkgs, home-manager } @ inputs: {

   nixosConfigurations = {
     "Cain" = nixpkgs.lib.nixosSystem {
       specialArgs = { inherit inputs; };
       system = "x86_64-linux";
       modules = [ ./config.nix ];
     };
   }; 

   homeConfigurations = {
     "deive@Cain" = home-manager.lib.homeManagerConfiguration {
       pkgs = nixpkgs.legacyPackages."x86_64-linux";
       modules = [ ./home.nix ];
     };
   };
 };
}
