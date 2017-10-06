#!/bin/bash

echo "Compile without opt"
icc 2_* -S -parallel -par-report2 -std=c99

echo "======================================"
# cat 2_1.s
echo "======================================"


echo "Compile with opt"
icc 2_*  -ipo-S -parallel -par-report2 -std=c99 -o optimized.out
echo "======================================"
# cat optimized.out
echo "======================================"
