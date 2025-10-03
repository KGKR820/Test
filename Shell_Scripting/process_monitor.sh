#!/bin/bash

echo "=== All Running Processes ==="
ps aux

echo "=== Process Count per User ==="
ps -eo user= | sort | uniq -c

echo "=== Top 5 CPU Consuming Processes ==="
ps -eo pid,comm,%cpu --sort=-%cpu | head -n 6

echo "=== Top 5 Memory Consuming Processes ==="
ps -eo pid,comm,%mem --sort=-%mem | head -n 6

read -p "Enter PID to kill (or press Enter to skip): " pid
if [ ! -z "$pid" ]; then
    read -p "Are you sure you want to kill PID $pid? (y/n): " confirm
    if [ "$confirm" == "y" ]; then
        kill -9 $pid
        echo "Process $pid killed."
    else
        echo "Action cancelled."
    fi
fi
