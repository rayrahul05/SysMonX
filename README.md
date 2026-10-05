SysMonX
Linux System, Hardware & Network Monitor
SysMonX is a lightweight Linux system-monitoring application written in C++17. It collects system, hardware, process, network, and operating-system information using Linux interfaces such as /proc, /etc/os-release, and POSIX/Linux system APIs.
The project also includes a Linux character-device driver starter under driver/, providing a foundation for learning user-space/kernel-space communication and device-driver development.
Features
System & Hardware Monitoring
- CPU architecture
- Number of CPU cores
- CPU utilization
- Total, used, and available memory
- System uptime
- Linux kernel version
- Linux distribution / OS information
Process Monitoring
- Total running process count
- Basic process listing
- Process information collected from /proc
Network Monitoring
- Network interface discovery
- RX byte statistics
- TX byte statistics
- Network information collected from /proc/net/dev
Linux System Programming
- /proc filesystem access
- /etc/os-release parsing
- uname() system call
- POSIX file operations
- Directory traversal using dirent
- Signal handling for SIGINT and SIGTERM
Device Driver Component
- Linux character-device module starter
- Dynamic device-number allocation
- cdev registration
- Basic open, read, and release operations
- /dev/sysmon device detection from user space
Note: The current driver is intentionally a learning starter. The final user-space/kernel-space protocol, including ioctl commands and data structures, is not implemented in this version.

Architecture
                    +----------------------+
                    |      SysMonX CLI      |
                    |       main.cpp       |
                    +----------+-----------+
                               |
        +----------------------+----------------------+
        |          |            |          |          |
        v          v            v          v          v
 +-----------+ +----------+ +----------+ +----------+ +----------------+
 |  System   | | Network  | | Process  | | System   | |    Device      |
 |  Monitor  | | Monitor  | | Monitor  | | Software | |   Interface    |
 +-----+-----+ +----+-----+ +----+-----+ +----+-----+ +-------+--------+
       |             |            |            |              |
       v             v            v            v              v
   /proc/stat   /proc/net/dev   /proc     /etc/os-release  /dev/sysmon
   /proc/meminfo             filesystem      + uname()          |
   /proc/uptime                                             +----+----+
                                                           | Driver |
                                                           | module |
                                                           +-------+
Project Structure
SysMonX/
├── src/
│   ├── main.cpp
│   ├── SystemMonitor.h
│   ├── SystemMonitor.cpp
│   ├── NetworkMonitor.h
│   ├── NetworkMonitor.cpp
│   ├── ProcessMonitor.h
│   ├── ProcessMonitor.cpp
│   ├── SystemSoftware.h
│   ├── SystemSoftware.cpp
│   ├── DeviceInterface.h
│   ├── DeviceInterface.cpp
│   ├── SignalHandler.h
│   └── SignalHandler.cpp
│
├── driver/
│   ├── Makefile
│   └── sysmon_driver.c
│
├── tests/
│   └── smoke_test.sh
│
├── docs/
│   ├── STAGES.md
│   ├── 20_DAY_MAPPING.md
│   ├── TEST_PLAN.md
│   └── SDLC_AGILE.md
│
├── Makefile
└── README.md
Technologies Used
Technology	Purpose
C++17	Core application development
C	Linux kernel driver
Linux /proc	System, memory, network and process information
POSIX APIs	File/device and signal operations
Linux Kernel APIs	Character-device driver
GNU Make	Build automation
GCC / G++	Compilation
Bash	Smoke testing


Requirements
A Linux environment with:
- GCC / G++
- GNU Make
- C++17 support
- Linux /proc filesystem
- Linux kernel headers (only required for building the driver)
On Ubuntu/Debian:
sudo apt update
sudo apt install build-essential
For the optional kernel module:
sudo apt install linux-headers-$(uname -r)
Build the Application
Clone the repository:
git clone <YOUR_GITHUB_REPOSITORY_URL>
cd SysMonX
Build:
make
Run:
./bin/sysmonx
Clean the build:
make clean
Example Output
=============================================
                 SysMonX
   Linux System, Hardware & Network Monitor
=============================================

CPU Architecture : x86_64
CPU Cores        : 8
CPU Usage        : 12.4%
Memory Total     : 15880 MB
Memory Used      : 6420 MB
Memory Available : 9460 MB
Kernel           : 6.x.x
OS               : Ubuntu
Uptime           : 12345 seconds
Process Count    : 210

Network Interfaces
  lo        RX=10240         TX=10240
  eth0      RX=12345678      TX=8765432

Processes (sample)
  1       systemd
  2       kthreadd
  100     bash
  ...

Driver status: /dev/sysmon not present
Actual values depend on the Linux system where SysMonX is executed.
How It Works
CPU Usage
SysMonX reads CPU timing information from:
/proc/stat
It takes two CPU snapshots separated by a short interval and calculates utilization from the difference between total CPU time and idle time.
Memory
Memory information is obtained from:
/proc/meminfo
The application reports:
- Total memory
- Used memory
- Available memory
System Uptime
Uptime is read from:
/proc/uptime
Network Statistics
Network interface statistics are collected from:
/proc/net/dev
For each interface, SysMonX reports received and transmitted bytes.
Process Monitoring
The application scans numeric directories inside:
/proc
Each numeric directory represents a process ID. Basic process names are obtained from:
/proc/<PID>/comm
Operating-System Information
Kernel and architecture information are obtained using:
uname()
Linux distribution information is read from:
/etc/os-release
Signal Handling
SysMonX installs handlers for:
SIGINT
SIGTERM
This provides a basic mechanism for safely requesting application termination.
Linux Character Driver
The driver/ directory contains a starter Linux character-device module.
Build it with:
make driver
This invokes the driver-specific Makefile and builds the kernel module against:
/lib/modules/$(uname -r)/build
The current module provides:
- Character-device registration
- Dynamic major/minor number allocation
- open() callback
- read() callback
- release() callback
- Kernel logging through pr_info()
The driver currently returns a simple learning message when read.
Driver Limitation
The current driver is not a complete hardware-monitoring driver. It is a foundation for extending the project with:
- Custom device data structures
- ioctl() commands
- User/kernel data exchange
- Validation and error handling
- Integration with DeviceInterface
- A complete /dev/sysmon monitoring protocol
Testing
A basic smoke test is provided in:
tests/smoke_test.sh
Run:
chmod +x tests/smoke_test.sh
./tests/smoke_test.sh
The smoke test verifies that:
1. The project builds successfully.
2. The executable starts.
3. SysMonX output is generated.
4. CPU information is displayed.
5. Network information is displayed.
The project also contains a broader test plan in:
docs/TEST_PLAN.md
Development Areas
The project is structured so additional functionality can be added without replacing the existing monitoring modules.
Potential extensions include:
- CPU temperature and hardware sensor monitoring
- Per-process CPU and memory usage
- Disk-space monitoring
- TCP/UDP socket monitoring
- Configurable refresh intervals
- Continuous real-time monitoring mode
- Logging to files
- More complete device-driver communication
- ioctl()-based kernel/user-space communication
- Unit and integration tests
- Improved error handling
- Monitoring alerts and thresholds
Learning Objectives
SysMonX brings together several Linux and C++ concepts:
- C++17 programming
- Object-oriented modular design
- STL containers
- Linux /proc filesystem
- POSIX APIs
- Process management concepts
- Network statistics
- Signals
- File descriptors
- Character-device drivers
- User-space / kernel-space interaction
- GNU Make
- Linux development workflow
- Software development lifecycle and testing
Documentation
Additional project documentation is available in the docs/ directory:
Document	Description
STAGES.md	Six-stage project development process
20_DAY_MAPPING.md	Mapping between training topics and project implementation
TEST_PLAN.md	Functional and integration test plan
SDLC_AGILE.md	SDLC and Agile development documentation
