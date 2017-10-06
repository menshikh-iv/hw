#include <stdio.h>
#include <stdlib.h>
#define N 10000

extern float calculate(float *a, float *b);

int main()
{
    float *a,*b,res;
    int i;

    a = (float*)malloc(N*sizeof(float));
    b = (float*)malloc(N*sizeof(float));
    for(i=0;i<N;i++)
    {
	a[i] = i;
        b[i] = 1 - i;
    }
    res =  calculate(a,b);
    printf("res = %f", res);
}
