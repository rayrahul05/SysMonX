#include "DeviceInterface.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
bool DeviceInterface::openDevice(const std::string&p){closeDevice(); fd_=::open(p.c_str(),O_RDONLY); return fd_>=0;}
void DeviceInterface::closeDevice(){if(fd_>=0){::close(fd_);fd_=-1;}}
bool DeviceInterface::isOpen()const{return fd_>=0;}
bool DeviceInterface::isDevicePresent(const std::string&p)const{struct stat s{}; return stat(p.c_str(),&s)==0;}
