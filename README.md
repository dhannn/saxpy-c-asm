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
1. [Comparative Analysis of Performance](#comparative-analysis-of-performance)
    1. <a href="#debug-mode">Debug Mode</a>
    1. <a href="#release-mode">Release Mode</a>
    1. <a href="#comparing-debug-and-release-mode">Comparing Debug and Release Mode</a>
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
of (1) C and assembly program implementations, and (2) Release and Debug mode.

## Debug Mode
The figures below show the average runtimes (in seconds) of each vector size 
per kernel when executed on debug mode. It can be observed that the assembly 
language implementation with an average runtime of 0.0912 seconds shows consistently 
better performance than that of C's average runtime of 0.2340 seconds.
Moreover, the difference in execution time becomes much more apparent as the vector 
size increases. For instance, the gap between C and assembly's $2^{20}$ test cases is 
0.0018 seconds while the gap between C and assembly's $2^{28}$ test cases is 0.4023 seconds.<br><br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/0f85e73e-c161-4bd4-ad5b-8421fd07dc5f)
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/5d6f01e0-87f5-450d-b9c7-3ce8cf652821)<br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/7eb98ec0-716a-4996-9193-4d41c9910931)

## Release Mode
The figures below show the average runtime (in seconds) of each vector size 
per kernel when executed on release mode. Much like the runtimes observed in
debug mode,  the assembly language implementation with an average runtime of 0.0792 seconds 
shows consistently better performance than that of C's average runtime of 0.2344 seconds. In
addition, the difference in execution time becomes much more apparent as the
vector size increases. For instance, the gap between C and assembly's $2^{20}$ test cases is 
0.0026 seconds while the gap between C and assembly's $2^{28}$ test cases is 0.4357 seconds.<br><br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/800dc442-088f-40b0-b54b-9963faffc015)
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/0d99a74e-31b2-481f-9eba-3fa2245ea5fe)<br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/8a5c7cad-73e4-4e00-993d-06199c52044c)

## Comparing Debug and Release Mode
The figures below compare the average runtime (in seconds) with regards to their execution
mode. Aside from the C implementation's $2^{28}$ test cases, it can be observed that every other
case shows runs on Release Mode outperforming those on Debug Mode by a small margin. This can be 
noted as Release Mode's average runtime of 0.1568 seconds. is less than Debug Mode's 0.1626 seconds.<br><br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/15aa0d19-4924-41b4-b4bf-4a89a5e79dcb)<br>
![image](https://github.com/dhannn/saxpy-c-asm/assets/90260852/e0d601f9-3e0f-457e-9a84-d0ad24b26558)

# Insights
Overall, it can be observed that in this experiment, **assembly outperforms C**. At first glance, this
may seem confusing since the assembly source code is significantly longer than that of C's. However,
it is important to remember the characteristics of assembly language. As opposed to high-level
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

---

# Declaration of AI Use
In accordance with the directives of the Provost, which encourages the transparent use of AI technology 
to enhance projects, we hereby declare that we use AI technology to augment this hands-on activity. The 
following use cases illustrate our application of AI:

- Generation of code documentation: to minimize the tedious process of documenting code, we use AI to
document our original code for us.

For transparency, the following link shows the scope of AI use: 
[https://chat.openai.com/share/e4280f73-f1e0-4b0c-8364-14c439203b95](https://chat.openai.com/share/a547e9df-639b-4c6d-80f4-9066bf3ee802).

We guarantee that all aspects of the project beyond the aforementioned scope are entirely original and 
free from external influence.
