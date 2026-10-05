# SysMonX – Linux System, Hardware & Network Monitor

IMPORTANT: This is a learning scaffold aligned to the 20-day training syllabus. Your training instructions require the final project to be developed individually and without AI creating it. Use this repository to understand the structure, then implement, change, test and document the final version yourself.

## Training coverage
- Days 1–2: Computer Architecture – Hardware
- Days 3–4: Computer Architecture – Network
- Days 5–6: Linux OS + Git
- Days 7–10: C++ Programming
- Days 11–13: Linux System Programming
- Days 14–15: Linux Device Drivers
- Days 16–17: Computer Architecture – Software
- Days 18–19: SDLC + Agile
- Day 20: Capstone

## Current runnable features
- CPU architecture and core count
- CPU usage from /proc/stat
- Memory information from /proc/meminfo
- System uptime
- Linux distribution/kernel information
- Network interface RX/TX statistics from /proc/net/dev
- Process count and a small process listing from /proc
- Basic POSIX signal handling
- Modular C++17 source layout

## Build
```bash
sudo apt update
sudo apt install build-essential
make
./bin/sysmonx
```

## Optional driver
The `driver/` directory contains a character-device learning starter. Kernel-module compilation requires matching Linux kernel headers.

```bash
sudo apt install linux-headers-$(uname -r)
make driver
```

The driver is intentionally not the finished capstone. Complete the device communication design yourself (especially ioctl/data structures) after understanding each kernel API.

## Suggested individual implementation work
1. Add your own character-device protocol.
2. Add ioctl commands and validated data structures.
3. Connect `DeviceInterface` to `/dev/sysmon`.
4. Add TCP/UDP socket demonstrations if these were taught in your training.
5. Improve process-level metrics.
6. Add hardware sensor support only where your Linux environment exposes it.
7. Add unit/integration tests.
8. Replace placeholder UML/report content with your own diagrams and evidence.
9. Maintain genuine Git commits for each stage.

## Repository structure
```text
SysMonX/
├── src/
├── driver/
├── docs/
├── tests/
├── Makefile
└── README.md
```
