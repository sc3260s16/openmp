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
- Add ```printf("All done!\n");``` at the end of the program, outside of the parallel region. What do you notice when you run the program repeatedly?

**2. parallel-for** 

- Are variables declared inside of a parallel region defined as private or shared?
- Run your code with eight threads. How is the array split up across the threads? Is this behavior consistent for multiple instances of the program?
- Try changing the thread scheduling from *dynamic* to *static* - how is the array split up across threads now? Now try with the *guided* option (you will need to increase the loop size by an order of magnitude to see this difference clearly).

Something like:

	bash run.sh 8 > out
	grep -c "thread id: 0" out
	grep -c "thread id: 1" out
	...

might be useful for counting how data gets split up across threads.

**3. parallel-for-combined-directive**

- In C programs you can wrap long lines of code across multiple lines by including a backslash character at the end of a line (without a semicolon). Try splitting the long ```#pragma``` line across three lines.
- Explore some of the other clauses that parallel for loops support (https://computing.llnl.gov/tutorials/openMP/#DO). What's the difference between *private*, *firstprivate*, and *lastprivate*? What about the *collapse* clause?
- What are rules of thumb for declaring a variable as *shared* or *private*?

**4. sections**

- Run this code with 8 threads. How many threads end up processing data?
- Notice the absence of curly brackets {} inside each ```#pragma omp section``` block of code. Curly brackets are not needed if you are only enclosing a single line of code or a loop.
- Let's pretend we want to store the sum of arrays *c* and *d* into another array *e*. Where should we put that code? Are any other changes to the exisiting program needed?

**5. critical**

- Try commenting out the critical directive line, re-building, and running with a bunch of threads (a few hundred).

**6. reduce**

- What happens if you change the operator to a minus sign in the reduction clause? 

**7. threadprivate**