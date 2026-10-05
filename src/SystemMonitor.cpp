#include "SystemMonitor.h"
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>

bool SystemMonitor::readCpuTimes(unsigned long long& idle,
                                  unsigned long long& total) const {
    std::ifstream file("/proc/stat");
    std::string cpu;
    unsigned long long user{}, nice{}, system{}, idleTime{}, iowait{};
    unsigned long long irq{}, softirq{}, steal{};

    if (!(file >> cpu >> user >> nice >> system >> idleTime
               >> iowait >> irq >> softirq >> steal)) {
        return false;
    }

    idle = idleTime + iowait;
    total = user + nice + system + idleTime + iowait
          + irq + softirq + steal;
    return true;
}

double SystemMonitor::cpuUsage() {
    unsigned long long idle1{}, total1{}, idle2{}, total2{};

    if (!readCpuTimes(idle1, total1))
        return -1.0;

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    if (!readCpuTimes(idle2, total2))
        return -1.0;

    const auto idleDelta = idle2 - idle1;
    const auto totalDelta = total2 - total1;

    if (totalDelta == 0)
        return 0.0;

    return 100.0 * (1.0 - static_cast<double>(idleDelta) /
                           static_cast<double>(totalDelta));
}

MemoryInfo SystemMonitor::memory() const {
    std::ifstream file("/proc/meminfo");
    std::string key;
    long long value{};
    std::string unit;

    long long totalKB = 0;
    long long availableKB = 0;

    while (file >> key >> value >> unit) {
        if (key == "MemTotal:")
            totalKB = value;
        else if (key == "MemAvailable:")
            availableKB = value;
    }

    MemoryInfo result;
    result.totalMB = totalKB / 1024;
    result.freeMB = availableKB / 1024;
    result.usedMB = result.totalMB - result.freeMB;
    return result;
}

std::uint64_t SystemMonitor::uptimeSeconds() const {
    std::ifstream file("/proc/uptime");
    double seconds{};
    file >> seconds;
    return static_cast<std::uint64_t>(seconds);
}
