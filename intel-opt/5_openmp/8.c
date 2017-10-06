#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define N 500000
#define MAX_ITER 100

/*
Элементы массива a инициализируются 0, массива b[0]...b[n-1] – случайными числами от 0 до n-1. 
Распараллелить цикл for (i=0; i<n; i++) a[b[i]]++;
*/

int main() {
    srand(0);

    int a[N], b[N], prior[N];
    float full_time = 0.;
    struct timeval start_s, end_s;

    for (int iter = 0; iter < MAX_ITER; iter++){
        for (int i = 0; i < N; i++){
            a[i] = prior[i] = 0;
            b[i] = (int)((rand() >> 15) % N);
        }

        gettimeofday(&start_s, NULL);

        #pragma omp parallel for
        for (int i = 0; i < N; i++){
            #pragma omp atomic
            a[b[i]]++;
        }
        gettimeofday(&end_s, NULL);

        for (int i = 0; i < N; i++){
            prior[b[i]]++;
        }

        for (int i = 0; i < N; i++){
            if (a[b[i]] != prior[b[i]]){
                printf("Raise condition detected, index #%d (%d, %d)\n", i, a[b[i]], prior[b[i]]);
                return 1;
            } 
        }



        full_time += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
                       end_s.tv_usec - start_s.tv_usec) / 1.e6;
    }
    printf("time: %f sec\n", full_time / MAX_ITER);
}
