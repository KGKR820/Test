#!/bin/bash

read -p "Enter number of passwords: " n
read -p "Enter password length: " len

for i in $(seq 1 $n); do
    openssl rand -base64 48 | cut -c1-$len
done
