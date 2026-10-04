# SysMonX — Linux System Monitor (Starter)

**Important:** This is a learning starter/scaffold, not a submission-ready capstone.
Your training instructions require the final project to be developed individually without AI-generated implementation. Use this repository to understand the structure, then write/modify the implementation yourself.

## Features currently demonstrated
- Linux `/proc` based CPU, memory and uptime monitoring
- C++17 application
- Modular C++ structure
- Makefile
- Optional kernel-module starter under `driver/`

## Build and run

Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
make
./bin/sysmonx
```

If kernel headers are unavailable in your environment, the C++ application can still be built with:

```bash
make app
./bin/sysmonx
```

## Optional driver

The `driver/` directory contains a minimal character-device learning skeleton. Kernel modules require a suitable Linux kernel and matching headers. Do not load code you do not understand.

```bash
make driver
```

The driver is intentionally only a starter and is not the completed capstone implementation.

## Suggested next work
1. Design your own driver data structures.
2. Implement your own `read()`/`ioctl()` interface.
3. Connect the C++ application to `/dev/sysmon`.
4. Add process monitoring.
5. Add tests and error handling.
6. Create your UML diagrams and report.
7. Commit progress regularly to your own GitHub repository.
