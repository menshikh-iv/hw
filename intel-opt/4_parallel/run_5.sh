#!/bin/bash

echo "Compile without opt"
icc 5.c -std=c99 -O0 -w -o 5_default
echo "Compile with parallel"
icc 5.c -std=c99 -w -parallel -par-report2 -o 5_gap

echo "Default version (no parallel)"
./5_default

echo
echo "Optimized version (GAP)"
./5_gap


rm 5_default 5_gap
