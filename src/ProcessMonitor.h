#pragma once
#include <string>
#include <vector>
struct ProcessInfo { int pid{}; std::string name; };
class ProcessMonitor { public: int count() const; std::vector<ProcessInfo> snapshot(std::size_t limit) const; };
