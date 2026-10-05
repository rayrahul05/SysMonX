#include "SystemMonitor.h"
#include "NetworkMonitor.h"
#include "ProcessMonitor.h"
#include "SystemSoftware.h"
#include "DeviceInterface.h"
#include "SignalHandler.h"
#include <iomanip>
#include <iostream>

int main() {
    SignalHandler::install();
    SystemMonitor sm; NetworkMonitor nm; ProcessMonitor pm; SystemSoftware ss; DeviceInterface dev;
    auto mem=sm.memory(); auto net=nm.interfaces(); auto procs=pm.snapshot(8); auto sw=ss.info();
    std::cout<<"\n=============================================\n";
    std::cout<<"                 SysMonX\n";
    std::cout<<"   Linux System, Hardware & Network Monitor\n";
    std::cout<<"=============================================\n\n";
    std::cout<<std::fixed<<std::setprecision(1);
    std::cout<<"CPU Architecture : "<<sw.architecture<<"\n";
    std::cout<<"CPU Cores        : "<<sw.cpuCores<<"\n";
    std::cout<<"CPU Usage        : "<<sm.cpuUsage()<<"%\n";
    std::cout<<"Memory Total     : "<<mem.totalMB<<" MB\n";
    std::cout<<"Memory Used      : "<<mem.usedMB<<" MB\n";
    std::cout<<"Memory Available : "<<mem.availableMB<<" MB\n";
    std::cout<<"Kernel           : "<<sw.kernel<<"\n";
    std::cout<<"OS               : "<<sw.osName<<"\n";
    std::cout<<"Uptime           : "<<sm.uptimeSeconds()<<" seconds\n";
    std::cout<<"Process Count    : "<<pm.count()<<"\n\n";
    std::cout<<"Network Interfaces\n";
    for(const auto& i: net) std::cout<<"  "<<std::left<<std::setw(10)<<i.name<<"RX="<<std::setw(14)<<i.rxBytes<<"TX="<<i.txBytes<<"\n";
    std::cout<<"\nProcesses (sample)\n";
    for(const auto& p: procs) std::cout<<"  "<<std::left<<std::setw(8)<<p.pid<<p.name<<"\n";
    std::cout<<"\nDriver status: "<<(dev.isDevicePresent("/dev/sysmon")?"/dev/sysmon found":"/dev/sysmon not present")<<"\n";
    std::cout<<"\nThe driver protocol is intentionally a student implementation task.\n";
}
