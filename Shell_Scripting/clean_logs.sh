#!/bin/bash
LOG_DIR="/home/kgkr/Coding/OS_Assignment"

find $LOG_DIR -type f -mtime +30 -exec rm -f {} \;
echo "[$(date)] Old logs cleaned from $LOG_DIR" >> clean_logs.log
