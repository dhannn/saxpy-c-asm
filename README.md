# Evaluating Performance of Assembly vs. C Programs

TODO: Introduction about the theoretical benefit of assembly vs. higher 
level programming (enumerate some then focus on performance)

TODO: Pivot to this short experiment and its objective (compare assembly
language vs C in terms of runtime)

TODO: Introduce the rest of the write-up (the rest of the sections) and
a brief description for each.

# Contents
1. [Methodology](#Methodology)
    1. <a href="#saxpy-and-kernel-implementations">SAXPY and Kernel Implementations</a>
    1. <a href="#generating-test-cases">Generating Test Cases</a>
    1. <a href="#evaluation-of-performance">Evaluation of Performance</a>
1. <a href="#proof-of-correctness">Proof of Correctness</a>
1. <a href="#comparative-analysis-of-performance">Comparative Analysis of Performance</a>
1. <a href="#insights">Insights</a>

# Methodology

## SAXPY and Kernel Implementations

For this experiment, we implemented a vector operation known mnemonically 
as SAXPY. Given vectors $X$ and $Y$, and a scalar $a$, SAXPY calculates vector $Z$: 
$$Z = aX+ Y.$$

We implemented the kernel implementation of SAXPY both in assembly 
(in `saxpy.asm`) and in C (in `saxpy.c` with its corresponding header file).

The C file `main.c` acts as a driver that calls necessary functions to a) verify
the correctness of the two implementation and b) measure the runtime.

## Generating Test Cases

TODO: Explain that we created a Python script to automate the generation of 
random values for test cases. Emphasize that we get random bytes and interpret
it as float (see source code if you want) then save it on a file `testcase_*` 
which the C program will read for input (both for correctness check and 
performance)

## Evaluation of Performance

TODO: why yes

# Proof of Correctness

TODO: Show the standard output and the file input

TODO: Explain briefly that the standard output that prints the first ten values
of Z in the kernel is equal to the expected output file input showed in the file
input

# Comparative Analysis of Performance

TODO: Put screenshots of the CSV file for both debug and release mode 
(or if you're feeling extra, you can have a simple Python script that will
make a graph out of the CSV HAHA)

TODO: Describe the table/csv. What are the average runtimes for each experiment? 
Which experiment type has the worst performance? The best? What are the trends?

# Insights

TODO: Tie everything together. What insights can we gleam from this short 
experiment? Make sure to bring back the things we've mentioned in the intro
