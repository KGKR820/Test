#!/bin/bash

LOG_FILE="system_alerts.log"
CPU=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
MEM=$(free | grep Mem | awk '{print $3/$2 * 100.0}')
DISK=$(df / | grep / | awk '{print $5}' | sed 's/%//')

echo "[$(date)] CPU=$CPU% MEM=$MEM% DISK=$DISK%" >> $LOG_FILE

if (( ${CPU%.*} > 80 )); then
    echo "[$(date)] ALERT: High CPU usage: $CPU%" >> $LOG_FILE
fi
if (( ${MEM%.*} > 75 )); then
    echo "[$(date)] ALERT: High Memory usage: $MEM%" >> $LOG_FILE
fi
if (( $DISK > 90 )); then
    echo "[$(date)] ALERT: Disk space critical: $DISK%" >> $LOG_FILE
fi
