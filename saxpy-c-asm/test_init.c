#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

struct testcase {
	int n;
	double A;
	float* X;
	float* Y;
	float* expected_Z;
	float* actual_Z;
};

void initialize_testcase(struct testcase *tc, char *testcase_filename) {
	printf("Initializing testcase from file %s...\n", testcase_filename);

	FILE* file = fopen(testcase_filename, "r");

	int n;
	int _ = fscanf(file, "%d", &n);

	tc->n = n;
	tc->X = calloc(n, sizeof(float));
	tc->Y = calloc(n, sizeof(float));
	tc->expected_Z = calloc(n, sizeof(float));
	tc->actual_Z = calloc(n, sizeof(float));
	_ = fscanf(file, "%lf", &(tc->A));

	for (int i = 0; i < n; i++) {
		_ = fscanf(file, "%f", tc->X + i);
		_ = fscanf(file, "%f", tc->Y + i);
		_ = fscanf(file, "%f", tc->expected_Z + i);
	}
	
	fclose(file);
}

void flush_answer(struct testcase tc) {
	for (int i = 0; i < tc.n; i++) {
		(tc.actual_Z)[i] = 0.0f;
	}
}

void free_testcases(struct testcase *tc) {
	free(tc->X);
	free(tc->Y);
	free(tc->expected_Z);
}
