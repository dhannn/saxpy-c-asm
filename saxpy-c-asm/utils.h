#pragma once

void verify_correctness_c(struct testcase);
void verify_correctness_assembly(struct testcase);

double time_implementation_c(struct testcase);
double time_implementation_assembly(struct testcase);

void initialize_runtime_header();
void log_runtime(char*, int, double);

void display_first_n(int, float*);
