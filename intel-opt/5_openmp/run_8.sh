#!/bin/bash

gcc 8.c -fopenmp -w -o 8_omp
gcc 8.c -w -o 8_default

echo "Default version"
./8_default

echo
echo "OMP version"
OMP_NUM_THREADS=16 ./8_omp


rm 8_omp 8_default

