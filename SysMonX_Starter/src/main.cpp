#include "SystemMonitor.h"
#include <iostream>
#include <iomanip>

int main() {
    SystemMonitor monitor;

    auto cpu = monitor.cpuUsage();
    auto mem = monitor.memory();
    auto uptime = monitor.uptimeSeconds();

    std::cout << "\n====================================\n";
    std::cout << "             SysMonX\n";
    std::cout << "      Linux System Monitor\n";
    std::cout << "====================================\n";

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "CPU Usage      : " << cpu << "%\n";
    std::cout << "Memory Total   : " << mem.totalMB << " MB\n";
    std::cout << "Memory Used    : " << mem.usedMB << " MB\n";
    std::cout << "Memory Free    : " << mem.freeMB << " MB\n";
    std::cout << "Uptime         : " << uptime << " seconds\n";

    std::cout << "\nNote: current starter reads Linux /proc directly.\n";
    std::cout << "The capstone task is to design and implement your own\n";
    std::cout << "kernel-driver communication layer.\n\n";

    return 0;
}
