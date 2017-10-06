#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#define M 300
#define N 400
#define K 200

#define MAX_ITER 5



/*
Написать программу по перемножению матриц. Запустить программу с автоматическим распараллеливанием и без него, оценить разницу
*/

int main(){
    srand(0);
    float m1[M][N], m2[N][K], result[M][K];
    float full_time = 0.;
    struct timeval start_s, end_s;


    for (int iter = 0; iter < MAX_ITER; iter++){
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                m1[i][j] = rand();
            }
        }
        for (int i = 0; i < N; i++){
            for (int j = 0; j < K; j++){
                m2[i][j] = rand();
            }
        }
        gettimeofday(&start_s, NULL);

        float sum = 0.;
        #pragma parallel
        for (int i = 0; i < M; i++){
            for(int j = 0; j < K; j++){
                sum = 0.;
                for(int k = 0; k < N; k++){
                    sum += m1[i][k] * m2[k][j];
                }
                result[i][j] = sum;
            }
        }

        gettimeofday(&end_s, NULL);
        printf("%f\n", result[0][0]);
        full_time += ((end_s.tv_sec  - start_s.tv_sec) * 1000000u +
                       end_s.tv_usec - start_s.tv_usec) / 1.e6;
    }
    printf("time: %f sec\n", full_time / MAX_ITER);
}
