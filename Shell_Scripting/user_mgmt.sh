#!/bin/bash

LOG_FILE="user_mgmt.log"

echo "1. Add User"
echo "2. Delete User"
read -p "Choose an option: " opt

case $opt in
    1)
        read -p "Enter username to add: " uname
        sudo useradd -m -d /home/$uname -s /bin/bash $uname
        sudo chmod 700 /home/$uname
        echo "[$(date)] Added user $uname" >> $LOG_FILE
        ;;
    2)
        read -p "Enter username to delete: " uname
        sudo userdel -r $uname
        echo "[$(date)] Deleted user $uname" >> $LOG_FILE
        ;;
    *)
        echo "Invalid option"
        ;;
esac
