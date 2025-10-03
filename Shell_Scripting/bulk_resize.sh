#!/bin/bash

INPUT_DIR="./images"
OUTPUT_DIR="./resized"
mkdir -p $OUTPUT_DIR

for img in $INPUT_DIR/*.{jpg,png,jpeg}; do
    [ -e "$img" ] || continue
    filename=$(basename "$img")
    convert "$img" -resize 800x600 "$OUTPUT_DIR/$filename"
    echo "Resized $filename"
done
