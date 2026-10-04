# Test Plan

| ID | Test | Expected Result |
|---|---|---|
| T01 | Build C++ application | Application builds successfully |
| T02 | Run monitor | CPU/memory/uptime are displayed |
| T03 | Invalid device path | Application handles failure safely |
| T04 | Build kernel module | Module builds on supported Linux kernel |
| T05 | Load driver | Kernel reports successful registration |
| T06 | Read device | Expected driver response is returned |
| T07 | Unload driver | Module unregisters cleanly |

Add your own tests after implementing the final design.
