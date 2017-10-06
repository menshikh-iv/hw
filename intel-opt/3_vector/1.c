#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define N 100000
#define MAX_ITER 100

int main(){
	srand(time(0));

	float a_fl[N], b_fl[N];
	double a_dl[N], b_dl[N];

	float full_time_fl = 0.;
	float full_time_dl = 0.;
	float result_1 = 0.;
	double result_2 = 0.;

	struct timeval start_s, end_s;


	for (int iter = 0; iter < MAX_ITER; iter++){
		for (int i = 0; i < N; i++){
			a_fl[i] = (float)rand()/(float)RAND_MAX;
			b_fl[i] = (float)rand()/(float)RAND_MAX;
		}
	    gettimeofday(&start_s, NULL);
		for (int i = 0; i < N; i++){
			result_1 += a_fl[i] * b_fl[i];
		}
		gettimeofday(&end_s, NULL);
	    full_time_fl += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
	              		  end_s.tv_usec - start_s.tv_usec) / 1.e6;

		for (int i = 0; i < N; i++){
			a_dl[i] = (double)rand()/(double)RAND_MAX;
			b_dl[i] = (double)rand()/(double)RAND_MAX;
		}
	    gettimeofday(&start_s, NULL);
	    for (int i = 0; i < N; i++){
			result_2 += a_dl[i] * b_dl[i];
		}
		gettimeofday(&end_s, NULL);
	    full_time_dl += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
	              		  end_s.tv_usec - start_s.tv_usec) / 1.e6;
	}

	printf("time [float]: %f sec (%f)\n", full_time_fl / MAX_ITER, result_1);
	printf("time [double]: %f sec (%f)\n", full_time_dl / MAX_ITER, result_2);
}
