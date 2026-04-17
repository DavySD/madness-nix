{config, ...}:
{

  zramSwap = {
    enable = true;
    memoryPercent = 50;
    algorithm = "zstd";
  };

  boot.kernel.sysctl = { "vm.swappiness" = 60; };

}
