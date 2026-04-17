# λ | Madness Nix - NixOS
*"Why would anyone use this?"*

![NixOS](https://img.shields.io/badge/NixOS-5277C3?logo=nixos&logoColor=white)
![Home Manager](https://img.shields.io/badge/Home%20Manager-blue?logo=homeadvisor&logoColor=white)

![Flakes](https://img.shields.io/badge/Flakes-5E81AC?logo=nixos&logoColor=white)
![Lix](https://img.shields.io/badge/Lix-FF5C8D?logo=nixos&logoColor=white&labelColor=FF5C8D)

My **source files** for my current *NixOS* system, with several changes and additions that you probably don't need.

---

## 👁️ | Components

- **Flake file**: [Flake](https://github.com/HavanaHL/madness-nix/blob/main/nixos/flake.nix )
- **Home-Manager**: [HM](https://github.com/HavanaHL/madness-nix/blob/main/nixos/home.nix)
- **Window Manager**: [Wayfire](https://wayfire.org/)
- **Lix**: [Lix](https://lix.systems/)
- **Compilation Overlays**: [gm/powerpills/overlays](https://github.com/HavanaHL/madness-nix/tree/main/nixos/gm/powerpills/overlays)

---

## ❄️ | Structure (16/04/26)
```bash
/etc/nixos
├── config.nix
├── flake.lock
├── flake.nix
├── gm
│   ├── fltp
│   │   └── fltp.nix
│   ├── hw
│   │   ├── default.nix
│   │   ├── pipewire.nix
│   │   ├── swap.nix
│   │   └── vp.nix
│   ├── pkgs
│   │   ├── default.nix
│   │   └── extra
│   │       └── thunar.nix
│   ├── powerpills
│   │   ├── cpu.nix
│   │   ├── hibernate.nix
│   │   └── overlays
│   │       ├── default.nix
│   │       └── mesa.nix
│   ├── scy
│   │   └── doas.nix
│   └── ui
│       ├── labwc.nix
│       └── src
│           └── DWM-FILES.zip
├── hardware-configuration.nix
├── hm
│   ├── env
│   │   ├── dft.nix
│   │   └── var.nix
│   ├── look
│   │   └── gui.nix
│   ├── overlays
│   │   ├── default.nix
│   │   └── zellij-0.nix
│   ├── pkgs
│   │   ├── default.nix
│   │   ├── extra
│   │   │   └── default.nix
│   │   └── fonts
│   │       └── default.nix
│   └── shell
│       └── zsh.nix
└── home.nix

19 directories, 28 files
``` 
