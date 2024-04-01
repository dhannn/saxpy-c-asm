/**
*	 
*/

#include <stdio.h>
void saxpy_c(int n, float *Z, double A, float *X, float *Y) {
	for (int i = 0; i < n; i++) {
		Z[i] = A * X[i] + Y[i];
	}
}
