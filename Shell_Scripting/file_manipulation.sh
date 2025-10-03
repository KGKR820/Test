#!/bin/bash

for i in {1..10}
do
    filename="file$i.txt"
    touch "$filename"
    echo "Created $filename"
    echo "Timestamp: $(date)" >> "$filename"
done

tar -czf files_archive.tar.gz file*.txt
echo "All files compressed into files_archive.tar.gz"
