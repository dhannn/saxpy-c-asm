#pragma once
#pragma warning(disable : 4996)

struct testcase {
	int n;
	double A;
	float* X;
	float* Y;
	float* expected_Z;
	float* actual_Z;
};

void initialize_testcase(struct testcase*, char*);
void flush_answer(struct testcase);
void free_testcases(struct testcase*);
