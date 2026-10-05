# Test Plan

| ID | Test | Expected |
|---|---|---|
| T01 | make | Build succeeds |
| T02 | run app | System information shown |
| T03 | CPU | Utilization shown |
| T04 | memory | Total/used/available shown |
| T05 | network | Interfaces and RX/TX shown |
| T06 | process | Process count/list shown |
| T07 | missing device | Safe status message |
| T08 | driver build | Module builds on supported kernel |
| T09 | driver load/unload | Clean module lifecycle |
| T10 | final integration | App communicates with driver |
