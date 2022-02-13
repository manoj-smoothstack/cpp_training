
/*****************************************************************************
                    C-DAC Tech Workshop : hyPACK-2013 
                         October 15-18, 2013 

 Example               : omp-matrix-transpose.c

 Objective             : Write an OpenMP Program for Transpose of a Matrix
                  	 and measure the performance.
                  	 This example demonstrates the use of
                  	 PARALLEL Directive and Private clause
 
 Input                 : a) Number of threads
         
                  	 b) Size of matrices (numofrows and noofcols )

 Output                : Each thread transposes assaigned Row and finally
                  	 master prints the result of the matrix transpose, the status of 
                  	 execution i.e. compare the result of the serial and parallel
                  	 execution and time taken for this.
	                                            
 Created             : August-2013

 E-mail              : hpcfte@cdac.in     

************************************************************************/

#include <stdio.h>
#include <sys/time.h>
#include <omp.h>
#include <stdlib.h>

/* Main Program */
int main(int argc,char **argv) {
	int             NoofRows, NoofCols, i, j,Total_threads,Noofthreads;
	float         **Matrix, **Trans, **Checkoutput, flops;

	struct timeval  TimeValue_Start;
	struct timezone TimeZone_Start;

	struct timeval  TimeValue_Final;
	struct timezone TimeZone_Final;
	long            time_start, time_end;
        double        time_overhead;

	printf("\n\t\t---------------------------------------------------------------------------");
        printf("\n\t\t Centre for Development of Advanced Computing (C-DAC)");
        printf("\n\t\t Email : hpcfte@cdac.in");
        printf("\n\t\t---------------------------------------------------------------------------");
        printf("\n\t\t Objective : Implementation of the transpose of matrix .");
        printf("\n\t\t using OpenMP Parallel for directive,Private Clause. ");
        printf("\n\t\t..........................................................................\n");

         /* Checking for command line arguments */
        if( argc != 4 ){

           printf("\t\t Very Few Arguments\n ");
           printf("\t\t Syntax : exec <Threads> <NoOfRows> <NoOfColumns>\n");
           exit(-1);
        }

        Noofthreads=atoi(argv[1]);
        if ((Noofthreads!=1) && (Noofthreads!=2) && (Noofthreads!=4) && (Noofthreads!=8) && (Noofthreads!= 16) ) {
               printf("\n Number of threads should be 1,2,4,8 or 16 for the execution of program. \n\n");
               exit(-1);
         }

	NoofRows=atoi(argv[2]);
        NoofCols=atoi(argv[3]);
/*	printf("\n\t\t Read The Matrix Size Noofrows And Colums Of Matrix \n");
	scanf("%d%d",&NoofRows,&NoofCols);*/

        printf("\n\t\t Threads : %d ",Noofthreads);
	printf("\n\t\t Matrix Size  : %d X %d \n  ",NoofRows,NoofCols);

	if (NoofRows <= 0 || NoofCols <= 0) {
		printf("\n\t\t The NoofRows And NoofCols Should Be Of Positive Sign\n");
		exit(1);
	}
	/* Matrix Elements */
	Matrix = (float **) malloc(sizeof(float *) * NoofRows);
	for (i = 0; i < NoofRows; i++) {
		Matrix[i] = (float *) malloc(sizeof(float) * NoofCols);
		for (j = 0; j < NoofCols; j++)
			Matrix[i][j] = (i * j) * 5 + i;
	}


	/* Dynamic Memory Allocation */
	Trans = (float **) malloc(sizeof(float *) * NoofCols);
	Checkoutput = (float **) malloc(sizeof(float *) * NoofCols);

	/* Initializing The Output Matrices Elements As Zero */
	for (i = 0; i < NoofCols; i++) {
		Checkoutput[i] = (float *) malloc(sizeof(float) * NoofRows);
		Trans[i] = (float *) malloc(sizeof(float) * NoofRows);
		for (j = 0; j < NoofRows; j++) {
			Checkoutput[i][j] = 0;
			Trans[i][j] = 0;
		}
	}

	 gettimeofday(&TimeValue_Start, &TimeZone_Start); 

	omp_set_num_threads(Noofthreads);
	
	/* OpenMP Parallel For Directive */
	#pragma omp parallel for private(j)
	for (i = 0; i < NoofRows; i = i + 1) {
                   Total_threads=omp_get_num_threads();
		for (j = 0; j < NoofCols; j = j + 1) {
			Trans[j][i] = Matrix[i][j];
                }
         } /* All thread join Master thread */

	  gettimeofday(&TimeValue_Final, &TimeZone_Final);

	time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
	time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
	time_overhead = (time_end - time_start)/1000000.0; 

	/* Serial Computation */
	for (i = 0; i < NoofRows; i = i + 1)
		for (j = 0; j < NoofCols; j = j + 1)
			Checkoutput[j][i] = Matrix[i][j];

	for (i = 0; i < NoofCols; i = i + 1)
		for (j = 0; j < NoofRows; j = j + 1)
			if (Checkoutput[i][j] == Trans[i][j])
				continue;
			else {
				printf("There Is A Difference From Serial And Parallel Calculation \n");
				exit(-1);
			}

/*	printf("The Input Matrix Is \n");
	for (i = 0; i < NoofRows; i++) {
		for (j = 0; j < NoofCols; j++)
			printf("%f \t", Matrix[i][j]);
		printf("\n");
	}

	printf("\nThe Transpose Matrix Is \n");
	for (i = 0; i < NoofCols; i = i + 1) {
		for (j = 0; j < NoofRows; j = j + 1)
			printf("%f \t", Trans[i][j]);
		printf("\n");
	}*/

	/* Calculation Of Flops */
 /*	flops = (float) 2 *NoofRows * NoofCols / (float) time_overhead; */
	/*printf("Time Taken :%lf \n Flops= %f Flops\n", time_overhead, flops); */
       
	 printf("\n\n\t\t Transpose of the matrix is ................ Done"); 
 	printf("\n\n\t\t Time in Seconds (T)         : %lf",time_overhead);
        printf("\n\n\t\t   ( T represents the Time taken for computation )");
        printf("\n\t\t..........................................................................\n");

	/* Freeing Allocated Memory */
	free(Matrix);
	free(Checkoutput);
	free(Trans);

}
