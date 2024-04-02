# Evaluating Performance of Assembly vs. C Programs

Assembly language, although generally less practiced than higher level programming 
languages like C and Java, is quite useful as it allows programmers to have direct
control over a computer's hardware. This makes efficient use of system resources such 
as memory and processing power as programmers can choose which parts of the hardware 
to utilize. Moreover, assembly language programs are generally faster than other programs 
written in high-level language. 

This experiment involves writing a kernel that performs the SAXPY ($AX + Y$) function in 
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
the correctness of the two implementations and b) measure the runtime.

## Generating Test Cases

We created a Python script to automate the generation of random values for test cases. 
This script generates random floats by utilizing the `random.uniform()` function and 
rounds them to two decimal places. The generated floats are then used to calculate 
corresponding values for the SAXPY operation ($AX + Y$). These values are saved in .txt
files named `testcase_correctness` and `testcase_*` which the C program will later read 
for both correctness checking and performance evaluation.

Specifically, we created test cases where the vector size (denoted by $n$) is 2 raised 
to the power of 20, 24, and 28.


## Evaluation of Performance

The performance of each kernel will be evaluated by running them 30 times for each 
vector size: $2^{20}$, $2^{24}$, and $2^{28}$, in both debug and release modes. The program will
calculate the average runtime for each kernel and vector size, and save this information
in a `.csv` file. Finally, we will compare the averages to see how the implementations 
perform relative to each other.

# Proof of Correctness

To validate the correctness of the SAXPY function implemented in both C and assembly, 
we generated 10 test cases, and stored their results, both actual and expected, in 2 .csv 
files. If all tests pass successfully, the program proceeds to the main experiment, where 
the SAXPY function is tested on vector sizes $2^{20}$, $2^{24}$, and $2^{28}$. This ensures 
that both implementations perform as expected before evaluating their performance.

The standard output prints the first ten values of Z in the terminal. If the program is 
implemented correctly, we can expect that these values are equal to the expected results
displayed in each implementation type's respective .csv file.

![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/0022da55-de5c-447d-abaa-9f5af571cda0)
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/0c59ff43-114d-41d2-b469-aa2c6a85e266)

# Comparative Analysis of Performance
As previously mentioned, we have decided to set the test cases to vector sizes $2^{20}$, 
$2^{24}$, and $2^{28}$. We conducted a comparative analysis specifically on the runtimes 
of (1) C and Assembly program implementations, and (2) Release and Debug mode.

## Debug Mode
The figures below show the average runtimes (in seconds) of each vector size 
per kernel when executed on debug mode. It can be observed that the assembly 
language implementation with an average runtime of 0.09122 seconds shows consistently 
better performance than that of C's average runtime of 0.234043333 seconds.
Moreover, the difference in execution time becomes much more apparent as the vector 
size increases. For instance, the gap between C and assembly's $2^{20}$ test cases is 
0.00177 seconds while the gap between C and assembly's $2^{28}$ test cases is 0.405 seconds.<br><br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/32821f3b-f669-4c1e-b79f-0efcba060ba3)
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/0622b397-ba3a-4138-85d5-3f3f8b9c4ab3)<br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/7eb98ec0-716a-4996-9193-4d41c9910931)

## Release Mode
The figures below show the average runtime (in seconds) of each vector size 
per kernel when executed on release mode. Much like the runtimes observed in
debug mode,  the assembly language implementation with an average runtime of 0.07921 seconds 
shows consistently better performance than that of C's average runtime of 0.23441 seconds. In
addition, the difference in execution time becomes much more apparent as the
vector size increases. For instance, the gap between C and assembly's $2^{20}$ test cases is 
0.00263 seconds while the gap between C and assembly's $2^{28}$ test cases is 0.4357 seconds.<br><br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/fb8a078b-4572-4c03-aad0-2fdb48c6240e)
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/bd2604b7-3649-47ff-92c6-7ce868297152)<br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/8a5c7cad-73e4-4e00-993d-06199c52044c)

## Comparing Debug and Release Mode
The figures below compare the average runtime (in seconds) with regards to their execution
mode. Aside from the C implementation's $2^{28}$ test cases, it can be observed that every other
case shows runs on Release Mode outperforming those on Debug Mode by a small margin. This can be 
noted as Release Mode's average runtime of 0.15681 seconds. is less than Debug Mode's 0.162631667 seconds.<br><br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/44cdfa0e-b840-4dbc-96b6-31e9e3dc060c) <br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/e0d601f9-3e0f-457e-9a84-d0ad24b26558)

# Insights
Overall, it can be observed that in this experiment, **Assembly outperforms C**. At first glance, this
may seem confusing since the Assembly source code is significantly longer than that of C's. However,
it is important to remember the characteristics of Assembly language. As opposed to high-level
programming languages like C, assembly does not require an intermediary like a compiler. Unlike C, 
assembly directly represents machine instructions, reducing the overhead of translation, and
ultimately, resulting in faster runtimes.

On the other hand, **running the program on Release Mode generally results in faster execution 
times than on Debug Mode** due to the absence of additional checks. In debug mode, the 
compiler adds extra checks and information to help with debugging, which makes the program 
slower to run. These checks and information are helpful for finding and fixing bugs 
during development. However, in release mode, these extras are removed to improve performance, 
resulting in faster execution of the program. Therefore, while debug mode is useful for debugging, 
release mode is faster for running the program without these extra checks.

It is important to note that although the differences in average runtime are quite small in 
this experiment, it is expected that with larger data, the performance gap between assembly 
and other high-level programming language will become more apparent. This allows us to further 
appreciate the wonders of assembly.
