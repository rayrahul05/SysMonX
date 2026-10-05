#include "SystemSoftware.h"
#include <fstream>
#include <string>
#include <sys/utsname.h>
#include <thread>
SystemSoftwareInfo SystemSoftware::info() const { SystemSoftwareInfo r; r.cpuCores=static_cast<int>(std::thread::hardware_concurrency()); utsname u{}; if(uname(&u)==0){r.kernel=u.release;r.architecture=u.machine;} std::ifstream f("/etc/os-release"); std::string line; while(std::getline(f,line)){ if(line.rfind("PRETTY_NAME=",0)==0){ r.osName=line.substr(12); if(r.osName.size()>=2&&r.osName.front()=='"'&&r.osName.back()=='"') r.osName=r.osName.substr(1,r.osName.size()-2); break; }} if(r.osName.empty()) r.osName="Unknown Linux"; return r; }
