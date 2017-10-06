#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define N 500000
#define MAX_ITER 30

/*
Написать программу, вычисляющую количество простых чисел в диапазоне от 2 до N. 
Ускорить ее с помощью OpenMP.
*/

main(){
    bool prime_cand[N];
    float full_time = 0.;
    int prime_count = 0;
    struct timeval start_s, end_s;

    for (int iter = 0; iter < MAX_ITER; iter++){
        prime_count = 0;
        for(int i = 0;i < N; i++){
            prime_cand[i] = true;
        }

        prime_cand[0] = prime_cand[1] = false;

        gettimeofday(&start_s, NULL);
        for(int i = 2; i * i < N; i++){
            #pragma omp parallel for schedule(static, 250)
            for(int j = i * i;j < N;j = j + i){
                prime_cand[j] = false;
            }
        }

        #pragma omp parallel for reduction(+:prime_count)
        for (int i = 0; i < N; i++){
            prime_count += prime_cand[i];
        }

        gettimeofday(&end_s, NULL);
        full_time += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
                       end_s.tv_usec - start_s.tv_usec) / 1.e6;
    }
    printf("time: %f sec\n", full_time / MAX_ITER);
}
