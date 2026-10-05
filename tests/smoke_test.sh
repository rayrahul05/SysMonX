#!/usr/bin/env bash
set -e
make
./bin/sysmonx >/tmp/sysmonx_output.txt
grep -q "SysMonX" /tmp/sysmonx_output.txt
grep -q "CPU Usage" /tmp/sysmonx_output.txt
grep -q "Network Interfaces" /tmp/sysmonx_output.txt
echo "Smoke test passed."
