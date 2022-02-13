#include <iostream>
#include <sys/time.h>
#include <omp.h>
#include <cassert>

typedef double TYPE;
#define MAX_VAL 1000
#define MIN_VAL 1

TYPE** randomSquareMatrix(int dimension) {
    /*
		    Generate 2 dimensional random TYPE matrix.
	  */

	  TYPE** matrix = (TYPE**)malloc(dimension * sizeof(TYPE*));
	  for (int i=0; i< dimension; i++) {
		    matrix[i] = (TYPE*)malloc(dimension * sizeof(TYPE));
	  }

	  //Random seed
	  srandom(time(0)+clock()+random());

	  #pragma omp parallel for
	  for(int i = 0; i < dimension; i++) {
		    for(int j = 0; j < dimension; j++) {
			      matrix[i][j] = rand() % MAX_VAL + MIN_VAL;
		    }
	  }
	  return matrix;
}

double parallelMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension, int nt) {
    struct timeval t0, t1;
	  gettimeofday(&t0, 0);

	  #pragma omp parallel for num_threads(nt)
	  for (int i = 0; i < dimension; i++) {
        assert(omp_get_num_threads() == 1);
		    for(int j = 0; j < dimension; j++) {
			      for(int k = 0; k <dimension; k++) {
				        matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			      }
		    }
	  }
	  gettimeofday(&t1, 0);
	  double elapsed = (t1.tv_sec-t0.tv_sec) * 1.0f + (t1.tv_usec - t0.tv_usec) / 1000000.0f;
	  return elapsed;
}

int main(void) {
    int dimension = 10;
    int nt = 4;
    TYPE** mat1 = randomSquareMatrix(dimension);
    TYPE** mat2 = randomSquareMatrix(dimension);
    TYPE** res = randomSquareMatrix(dimension);
    double elapsed = parallelMultiply(mat1, mat2, res, dimension, nt);
    std::cout << elapsed << std::endl;
}
