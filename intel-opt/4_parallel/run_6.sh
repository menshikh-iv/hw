#!/bin/bash

icc 6.c -std=c99 -O0 -w -o 6_default
icc 6.c -std=c99 -w -parallel -guide-par -par-report1 -o 6_gap

echo "Default version (no parallel)"
./6_default

echo
echo "Optimized version (GAP)"
./6_gap


rm 6_default 6_gap
