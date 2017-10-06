#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define N 1000000
#define MAX_ITER 25

/*
Ускорить выполнение цикла for в программе, вычисляющей
покоординатную функцию от элементов массива a: a[i]=F(a[i]);
*/

float func(float element){
    return element * element * element - element * 0.15;
}

int main() {
    srand(time(0));

    float a[N];
    float full_time = 0.;
    struct timeval start_s, end_s;

    for (int iter = 0; iter < MAX_ITER; iter++){
        for (int i = 0; i < N; i++){
            a[i] = (float)rand()/(float)RAND_MAX;
        }

        gettimeofday(&start_s, NULL);
        #pragma omp parallel for
        for (int i = 0; i < N; i++){
            a[i] = func(a[i]);
        }
        gettimeofday(&end_s, NULL);

        full_time += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
                       end_s.tv_usec - start_s.tv_usec) / 1.e6;
    }
    printf("time: %f sec\n", full_time / MAX_ITER);
}
