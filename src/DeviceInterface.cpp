#include "DeviceInterface.h"
#include <fcntl.h>
#include <unistd.h>

bool DeviceInterface::openDevice(const std::string& path) {
    closeDevice();
    fd_ = ::open(path.c_str(), O_RDONLY);
    return fd_ >= 0;
}

void DeviceInterface::closeDevice() {
    if (fd_ >= 0) {
        ::close(fd_);
        fd_ = -1;
    }
}

bool DeviceInterface::isOpen() const {
    return fd_ >= 0;
}
