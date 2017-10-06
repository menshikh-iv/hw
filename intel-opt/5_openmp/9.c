#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define N 1000000
#define MAX_ITER 50

/*
Распараллелить цикл вычисления суммы
    for (i=0; i<n; i++) sum+=F(i);
*/

double func(double element){
    return element * element * element - element * 0.15;
}

int main() {
    srand(0);

    double a[N];
    double full_time = 0.;
    double sum_res = 0.;
    struct timeval start_s, end_s;

    for (int iter = 0; iter < MAX_ITER; iter++){
        sum_res = 0.;
        for (int i = 0; i < N; i++){
            a[i] = (double)rand()/(double)RAND_MAX;
        }

        gettimeofday(&start_s, NULL);
        #pragma omp parallel for reduction(+:sum_res)
        for (int i = 0; i < N; i++){
            sum_res += func(a[i]);
        }
        gettimeofday(&end_s, NULL);
        if (iter == 0){
            printf("Sum: %f\n", sum_res);
        }

        full_time += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
                       end_s.tv_usec - start_s.tv_usec) / 1.e6;
    }
    printf("time: %f sec\n", full_time / MAX_ITER);
}
