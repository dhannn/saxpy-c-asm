#pragma once
#pragma warning(disable : 4996)
/**
 * @file test_init.h
 * @brief Header file containing declarations for initializing test cases.
 */

/**
 * @brief Struct representing a testcase with input and output data.
 */
struct testcase {
	int n;					/** Number of elements */
	double A;				/** Constant scalar */
	float* X;				/** Array of input data */
	float* Y;				/** Array of input data */
	float* expected_Z;		/** Array of expected output data */
	float* actual_Z;		/** Array of actual output data */
};

/**
 * @brief Initializes a testcase from a file.
 * 
 * @param tc Pointer to the testcase struct to be initialized.
 * @param testcase_filename Name of the file containing the testcase data.
 */
void initialize_testcase(struct testcase*, char*);

/**
 * @brief Resets the actual output data of a testcase.
 * 
 * @param tc The testcase struct whose actual output data will be reset.
 */
void flush_answer(struct testcase);

/**
 * @brief Frees memory allocated for testcase data.
 * 
 * @param tc Pointer to the testcase struct whose memory will be freed.
 */
void free_testcases(struct testcase*);
