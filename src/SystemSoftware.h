#pragma once
#include <string>
struct SystemSoftwareInfo { std::string osName,kernel,architecture; int cpuCores{}; };
class SystemSoftware { public: SystemSoftwareInfo info() const; };
