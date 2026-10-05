#pragma once
#include <string>

class DeviceInterface {
public:
    bool openDevice(const std::string& path);
    void closeDevice();
    bool isOpen() const;

private:
    int fd_ = -1;
};
