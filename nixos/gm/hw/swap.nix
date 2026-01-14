{config, ...}:
{

  zramSwap = {
    enable = true;
    memoryPercent = 50;
    algorithm = "lz4";
  };

  boot.kernel.sysctl = { "vm.swappiness" = 10; };

}
