#include "factorial.c"
#include <stdio.h>
#include <omp.h>
#include <math.h>

#define expX 1
static long num_steps = 3500;

// Serial para el calculo de e^2
int main(){
	int i, n;
	double sum = 0.0;
	double start_time, run_time;

	/*start timer */
	omp_set_num_threads(4);
	start_time = omp_get_wtime();

	#pragma omp parallel
	{
		#pragma omp for reduction(+:sum) private(n)

		for (i=0;i<= num_steps; i++){
			n = factorial(i);
			sum=sum+((pow(expX,i))/(n));
		}
	}
	run_time = omp_get_wtime() - start_time;
	printf("\n e^2 is %f in %f seconds \n",sum,run_time);
}