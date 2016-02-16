#!/bin/bash

if [[ $# -ne 1 ]] ; then
    echo "usage: ./sections num_threads"
    exit 1
fi
export OMP_NUM_THREADS=$1
./sections