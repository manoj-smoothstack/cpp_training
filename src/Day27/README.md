# Assignment

## Parallel Matrix Multiplication Template Class

We introduced the algorithm for parallel matrix multiplication using OpenMP:

```
#pragma omp parallel shared(matrixC) private(i, j, k, iOff, jOff, tot) num_threads(40)
{
    #pragma omp for schedule(static)
    for (i = 0;  i < dimension; i++) {
        iOff = i * dimension;
        for (j = 0; j < dimension; j++) {
            jOff = j * dimension;
            tot = 0;
            for (k = 0; k < dimension; k++) {
                tot += flatA[iOff + k] * flatB[jOff + k];
            }
            matrixC[i][j] = tot;
        }
    }
}
```

Write a complete program that creates the matrices and uses OpenMP to perform parallel
multiplication. Develop a templated class that can work with any numeric type.

## Parallel Matrix Multiplication For Rectangular Matrix Template Class

Modify the above assignment to work with rectangular matrices.
