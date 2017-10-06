#!/bin/bash

gcc 10_alt.c -fopenmp -w -o 10_omp
gcc 10_alt.c -w -o 10_default

echo "Default version"
./10_default

echo
echo "OMP version"
OMP_NUM_THREADS=4 ./10_omp


rm 10_omp 10_default

