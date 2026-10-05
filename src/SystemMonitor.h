#pragma once
#include <cstdint>
struct MemoryInfo { long long totalMB{}, usedMB{}, availableMB{}; };
class SystemMonitor { public: double cpuUsage(); MemoryInfo memory() const; std::uint64_t uptimeSeconds() const; private: bool readCpuTimes(unsigned long long&, unsigned long long&) const; };
