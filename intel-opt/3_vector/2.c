#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define N 100000
#define MAX_ITER 100


struct s_of_arrs{
	double a[N];
	double b[N];
};


struct el_of_arrs{
	double a;
	double b;
};

int main(){
	srand(time(0));
	struct el_of_arrs fst[N];
	struct s_of_arrs snd;

	double full_time_el_of_arrs = 0.;
	double full_time_s_of_arrs = 0.;
	double r_a, r_b;


	double result_1 = 0.;
	double result_2 = 0.;

	struct timeval start_s, end_s;

	for (int iter = 0; iter < MAX_ITER; iter++){
		for (int i = 0; i < N; i++){
			r_a = (double)rand()/(double)RAND_MAX;
			r_b = (double)rand()/(double)RAND_MAX;

			fst[i].a = r_a;
			fst[i].b = r_b;

			snd.a[i] = r_a;
			snd.b[i] = r_b;
		}
		
	    gettimeofday(&start_s, NULL);
		for (int i = 0; i < N; i++){
			result_1 += fst[i].a * fst[i].b;
		}
		gettimeofday(&end_s, NULL);
	    full_time_el_of_arrs += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
	              		  		  end_s.tv_usec - start_s.tv_usec) / 1.e6;

	    gettimeofday(&start_s, NULL);
	    for (int i = 0; i < N; i++){
			result_2 += snd.a[i] * snd.b[i];
		}
		gettimeofday(&end_s, NULL);
	    full_time_s_of_arrs += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
	              		  		 end_s.tv_usec - start_s.tv_usec) / 1.e6;
	}

	printf("time [array of structs]: %f sec (%f)\n", full_time_el_of_arrs / MAX_ITER, result_1);
	printf("time [struct of arrays]: %f sec (%f)\n", full_time_s_of_arrs / MAX_ITER, result_2);
}
