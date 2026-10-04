#pragma once
#include <cstdint>

struct MemoryInfo {
    long long totalMB{};
    long long usedMB{};
    long long freeMB{};
};

class SystemMonitor {
public:
    double cpuUsage();
    MemoryInfo memory() const;
    std::uint64_t uptimeSeconds() const;

private:
    bool readCpuTimes(unsigned long long& idle,
                      unsigned long long& total) const;
};
