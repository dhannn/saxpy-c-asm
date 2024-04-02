#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test_init.h"
#include "saxpy.h"
#include "utils.h" 


#define TEST_TYPE "release"
#define RUNS_PER_TESTCASE 30
#define MAX_TESTCASES 3

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
