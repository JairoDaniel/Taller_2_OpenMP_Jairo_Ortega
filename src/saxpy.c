
#include <stdio.h>
#include <omp.h>


#define vect_size 35000000

float vecX[vect_size], vecY[vect_size], vecZ[vect_size];
static float a= .85;


int main (){
	int i;
	double start_time, run_time;
	float sum =0.0;

	//Initialize vectors
	for(i=0; i<vect_size; i++){
		vecX[i]=(i+1)*0.35;
		vecY[i]=(i+1)*0.18;
	}

	start_time = omp_get_wtime();
	
	for(i=0; i<vect_size;i++){
		vecZ[i]=a*vecX[i]+vecY[i];
	}
	
	run_time = omp_get_wtime() - start_time;
	printf("\n process finished in %f seconds \n",run_time);
}