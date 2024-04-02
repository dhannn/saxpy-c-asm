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

/**
 * @brief Initializes a testcase from a file.
 * 
 * @param tc Pointer to the testcase struct to be initialized.
 * @param testcase_filename Name of the file containing the testcase data.
 */
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

/**
 * @brief Resets the actual output data of a testcase.
 * 
 * @param tc The testcase struct whose actual output data will be reset.
 */
void flush_answer(struct testcase tc) {
	for (int i = 0; i < tc.n; i++) {
		(tc.actual_Z)[i] = 0.0f;
	}
}

/**
 * @brief Frees memory allocated for testcase data.
 * 
 * @param tc Pointer to the testcase struct whose memory will be freed.
 */
void free_testcases(struct testcase *tc) {
	free(tc->X);
	free(tc->Y);
	free(tc->expected_Z);
}
