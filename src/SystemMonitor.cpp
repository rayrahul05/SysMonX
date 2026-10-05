#include "SystemMonitor.h"
#include <chrono>
#include <fstream>
#include <string>
#include <thread>

bool SystemMonitor::readCpuTimes(unsigned long long& idle,unsigned long long& total) const { std::ifstream f("/proc/stat"); std::string cpu; unsigned long long user{},nice{},system{},idleT{},iowait{},irq{},softirq{},steal{}; if(!(f>>cpu>>user>>nice>>system>>idleT>>iowait>>irq>>softirq>>steal)) return false; idle=idleT+iowait; total=user+nice+system+idleT+iowait+irq+softirq+steal; return true; }
double SystemMonitor::cpuUsage(){ unsigned long long i1,t1,i2,t2; if(!readCpuTimes(i1,t1)) return -1; std::this_thread::sleep_for(std::chrono::milliseconds(200)); if(!readCpuTimes(i2,t2)) return -1; auto di=i2-i1, dt=t2-t1; return dt?100.0*(1.0-static_cast<double>(di)/dt):0.0; }
MemoryInfo SystemMonitor::memory() const { std::ifstream f("/proc/meminfo"); std::string k,u; long long v,total=0,avail=0; while(f>>k>>v>>u){ if(k=="MemTotal:") total=v; else if(k=="MemAvailable:") avail=v;} return {total/1024,(total-avail)/1024,avail/1024}; }
std::uint64_t SystemMonitor::uptimeSeconds() const { std::ifstream f("/proc/uptime"); double s{}; f>>s; return static_cast<std::uint64_t>(s); }
