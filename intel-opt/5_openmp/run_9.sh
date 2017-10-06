#!/bin/bash

gcc 9.c -fopenmp -w -o 9_omp
gcc 9.c -w -o 9_default

echo "Default version"
./9_default

echo
echo "OMP version"
OMP_NUM_THREADS=4 ./9_omp


rm 9_omp 9_default

