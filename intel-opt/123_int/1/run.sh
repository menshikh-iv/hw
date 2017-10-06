#!/bin/bash

echo "Compile without opt"
icc 1_* -S

echo "======================================"
cat 1_1.s
echo "======================================"


echo "Compile with opt"
icc 1_*  -ipo-S -o optimized.out
echo "======================================"
cat optimized.out
echo "======================================"
