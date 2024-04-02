# Evaluating Performance of Assembly vs. C Programs

Assembly language, although generally less practiced than higher level programming 
languages like C and Java, is quite useful as it allows programmers to have direct
control over a computer's hardware. This makes efficient use of system resources such 
as memory and processing power as programmers can choose which parts of the hardware 
to utilize. Moreover, assembly language programs are generally faster than other programs 
written in high-level language. 

This experiment involves writing a kernel that performs the SAXPY (A*X + Y) function in 
(1) C program and (2) an x86-64 assembly. Using a main C program that calls both versions,
we aim to compare their runtimes by getting the average of 30 executions each on both
debug and release mode. From this, a short analysis of each kernel's performance will 
be derived.

In the following sections, we will cover how we conducted the experiment, including our 
methodology, proof of correctness, and a comparison of performance between the assembly 
and C implementations.

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

We created a Python script to automate the generation of random values for test cases. 
This script generates random floats by utilizing the random.uniform() function and 
rounds them to two decimal places. The generated floats are then used to calculate 
corresponding values for the SAXPY operation (A*X + Y). These values are saved in .txt
files named testcase_correctness and testcase_*, which the C program will later read 
for both correctness checking and performance evaluation.

Specifically, we created test cases where the vector size (denoted by 'n') is raised 
to the power of 20, 24, and 28.


## Evaluation of Performance

The performance of each kernel will be evaluated by running them 30 times for each 
vector size: n^20, n^24, and n^28, in both debug and release modes. The program will
calculate the average runtime for each kernel and vector size, and save this information
in a .csv file. Finally, we will compare the averages to see how the implementations 
perform relative to each other.

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

## Debug Mode
The figures below show the average runtimes (in seconds) of each vector size 
per kernel when executed on debug mode. It can be observed that the assembly 
language implementation shows consistently better performance than that of C's. <br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/32821f3b-f669-4c1e-b79f-0efcba060ba3)<br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/c17f5a87-664b-4d23-9c4c-91817df3a4f8)

## Release Mode

## Comparing Debug and Release Mode


# Insights

TODO: Tie everything together. What insights can we gleam from this short 
experiment? Make sure to bring back the things we've mentioned in the intro
