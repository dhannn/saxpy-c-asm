#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test_init.h"
#include "saxpy.h"

#define TEST_TYPE "release"
#define RUNS_PER_TESTCASE 30
#define MAX_TESTCASES 3

extern void saxpy_asm(long long int n, long long int Z, float A, long long int X, long long int Y);

void verify_correctness_c(struct testcase);
void verify_correctness_assembly(struct testcase);

double time_implementation_c(struct testcase);
double time_implementation_assembly(struct testcase);

void initialize_runtime_header();
void log_runtime(char*, int, double);

int main() {

	struct testcase tc;
	initialize_testcase(&tc, "testcase_correctness");
	verify_correctness_assembly(tc);
	free_testcases(&tc);

	initialize_testcase(&tc, "testcase_correctness");
	verify_correctness_c(tc);
	free_testcases(&tc);

	
	char* testcase_filenames[] = { "testcase_20", "testcase_24", "testcase_28" };
	int ns[] = { 20, 24, 28 };

	initialize_runtime_header();

	for (int test = 0; test < MAX_TESTCASES; test++) {
		
		double total_elapsed_time = 0;

		initialize_testcase(&tc, testcase_filenames[test]);
		for (int iter = 0; iter < RUNS_PER_TESTCASE; iter++) {
			
			double elapsed = time_implementation_c(tc);
			total_elapsed_time += elapsed;

			flush_answer(tc);
		}
		free_testcases(&tc);

		double average_runtime = total_elapsed_time / RUNS_PER_TESTCASE;
		log_runtime("c", ns[test], average_runtime);

	}

	for (int test = 0; test < MAX_TESTCASES; test++) {

		double total_elapsed_time = 0;

		initialize_testcase(&tc, testcase_filenames[test]);
		for (int iter = 0; iter < RUNS_PER_TESTCASE; iter++) {

			double elapsed = time_implementation_assembly(tc);
			total_elapsed_time += elapsed;

			flush_answer(tc);
		}
		free_testcases(&tc);

		double average_runtime = total_elapsed_time / RUNS_PER_TESTCASE;
		log_runtime("asm", ns[test], average_runtime);

	}

	return 0;
}

void log_correctness(struct testcase tc, char* implementation_type) {

	char filename[50] = "";
	sprintf(filename, "data/correctness_%s.csv", implementation_type);

	FILE* file = fopen(filename, "a");
	fprintf(file, "A,X,Y,expected_Z,actual_Z,status\n");

	printf("Verifying the correctness of %s implementation...\n\n", implementation_type);

	for (int i = 0; i < tc.n; i++) {

		double A = tc.A;
		float X = tc.X[i];
		float Y = tc.Y[i];
		float expected = tc.expected_Z[i];
		float actual = tc.actual_Z[i];

		char* status = "F";

		if (expected - actual <= 0.001 || expected - actual >= -0.001)
			status = "P";

		fprintf(file, "%.4f,%.4f,%.4f,%.4f,%.4f,%s\n", A, X, Y, expected, actual, status);
	}

	fclose(file);
}

void verify_correctness_c(struct testcase tc) {
	saxpy_c(tc.n, tc.actual_Z, tc.A, tc.X, tc.Y);
	log_correctness(tc, "C");
}

void verify_correctness_assembly(struct testcase tc) {
	saxpy_asm((long long int) tc.n, (long long int) tc.actual_Z, (float)tc.A, (long long int) tc.X, (long long int) tc.Y);
	log_correctness(tc, "assembly");
}

void initialize_runtime_header() {
	char filename[50] = "";
	sprintf(filename, "data/average_runtime_%s.csv", TEST_TYPE);

	FILE* file = fopen(filename, "a");

	fprintf(file, "implementation,n,average_runtime_in_ms\n");

	fclose(file);

}

void log_runtime(char *implementation_type, int n, double average_runtime) {
	char filename[50] = "";
	sprintf(filename, "data/average_runtime_%s.csv", TEST_TYPE);

	FILE* file = fopen(filename, "a");
	fprintf(file, "%s,%d,%.5f\n", implementation_type, n, average_runtime);
	fclose(file);
}

// https://stackoverflow.com/questions/5248915/execution-time-of-c-program
double time_implementation_c(struct testcase tc) {

	printf("Measuring the runtime for the C implementation of SAXPY...\n");
	
	clock_t before = clock();
	saxpy_c(tc.n, tc.actual_Z, tc.A, tc.X, tc.Y);
	clock_t after = clock();

	return (double)(after - before)/ (double) CLOCKS_PER_SEC;

}

double time_implementation_assembly(struct testcase tc) {

	printf("Measuring the runtime for the assembly implementation of SAXPY...\n");

	long long int n = (long long int) tc.n;
	long long int Z = (long long int) tc.actual_Z;
	float A = (float) tc.A;
	long long int X = (long long int) tc.X;
	long long int Y = (long long int) tc.Y;

	clock_t before = clock();
	saxpy_asm(n, Z, A, X, Y);
	clock_t after = clock();
	
	return (double)(after - before) / CLOCKS_PER_SEC;

}

