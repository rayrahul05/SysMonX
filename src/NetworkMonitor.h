#pragma once
#include <cstdint>
#include <string>
#include <vector>
struct NetworkInterfaceInfo { std::string name; std::uint64_t rxBytes{}, txBytes{}; };
class NetworkMonitor { public: std::vector<NetworkInterfaceInfo> interfaces() const; };
