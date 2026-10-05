#pragma once
#include <string>
class DeviceInterface { public: bool openDevice(const std::string&); void closeDevice(); bool isOpen() const; bool isDevicePresent(const std::string&) const; private: int fd_=-1; };
