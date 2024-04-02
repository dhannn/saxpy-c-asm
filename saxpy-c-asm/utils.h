#pragma once
/**
 * @file utils.h
 * @brief Header file containing declarations for utility functions.
 */


 /**
  * @brief Verifies the correctness of the C implementation of SAXPY.
  *
  * @param tc The testcase struct containing input data.
  */
void verify_correctness_c(struct testcase);

/**
 * @brief Verifies the correctness of the assembly implementation of SAXPY.
 *
 * @param tc The testcase struct containing input data.
 */
void verify_correctness_assembly(struct testcase);

/**
 * @brief Measures the runtime for the C implementation of SAXPY.
 *
 * @param tc The testcase struct containing input data.
 * @return The runtime in seconds.
 */
double time_implementation_c(struct testcase);
/**
 * @brief Measures the runtime for the assembly implementation of SAXPY.
 *
 * @param tc The testcase struct containing input data.
 * @return The runtime in seconds.
 */

double time_implementation_assembly(struct testcase);

/**
 * @brief Initializes the header for logging average runtime data.
 */
void initialize_runtime_header();
/**
 * @brief Logs the average runtime data to a CSV file.
 *
 * @param implementation_type The type of implementation ('C' or 'assembly').
 * @param n The size of the input data.
 * @param average_runtime The average runtime in milliseconds.
 */
void log_runtime(char*, int, double);

/**
 * @brief Displays the first n elements of an array.
 *
 * @param n The number of elements to display.
 * @param Z The array of floats.
 */

void display_first_n(int, float*);

