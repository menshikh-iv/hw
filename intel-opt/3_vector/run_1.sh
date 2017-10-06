#!/bin/bash

icc 1.c -std=c99 -w -O0 -o 1_O0
icc 1.c -std=c99 -w -O2 -vec-report1 -o 1_O2

echo "Default version (O0)"
./1_O0

echo
echo "Optimized version (O2)"
./1_O2


rm 1_O0 1_O2
