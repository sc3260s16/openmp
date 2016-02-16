# OpenMP

This repo contains examples for running OpenMP programs on the ACCRE cluster.

## Building Programs

Each example has a Makefile that assumes icc is used rather than gcc. 

	setpkgs -a intel_cluster_studio_compiler
	make

## Running Programs

All examples can be run with something like:

	bash run.sh 2

Where 2 is the number of threads to use for parallel portions of the program.

## Exercises

**1. hello**

- Run the program three times in a row with 8 threads. What do you notice?
- Try running the program without invoking the shell script (i.e. type ```./hello```). What is the default number of threads? Where does this value come from?

**2. parallel-for** 


**3. parallel-for-combined-directive**