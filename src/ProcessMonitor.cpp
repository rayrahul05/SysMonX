#include "ProcessMonitor.h"
#include <dirent.h>
#include <fstream>
#include <string>
static bool numeric(const std::string&s){ if(s.empty()) return false; for(char c:s) if(c<'0'||c>'9') return false; return true; }
int ProcessMonitor::count() const { DIR*d=opendir("/proc"); if(!d) return 0; int n=0; while(dirent*e=readdir(d)) if(numeric(e->d_name)) ++n; closedir(d); return n; }
std::vector<ProcessInfo> ProcessMonitor::snapshot(std::size_t limit) const { DIR*d=opendir("/proc"); std::vector<ProcessInfo> r; if(!d) return r; while(dirent*e=readdir(d)){ if(!numeric(e->d_name)||r.size()>=limit) continue; std::ifstream f(std::string("/proc/")+e->d_name+"/comm"); std::string name; if(f>>name) r.push_back({std::stoi(e->d_name),name}); } closedir(d); return r; }
