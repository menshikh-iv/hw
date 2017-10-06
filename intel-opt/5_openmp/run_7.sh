#!/bin/bash

gcc 7.c -fopenmp -w -o 7_omp
gcc 7.c -w -o 7_default

echo "Default version"
./7_default

echo
echo "OMP version"
OMP_NUM_THREADS=4 ./7_omp


rm 7_omp 7_default
