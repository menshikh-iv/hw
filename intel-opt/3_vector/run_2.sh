#!/bin/bash

icc 2.c -std=c99 -w -O2 -vec-report3 -o 2_O2

./2_O2


rm 2_O2
