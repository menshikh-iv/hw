#include <stdio.h>
#define N 10000

extern float calc(float a, float b);

float calculate(float * restrict a, float * restrict b)
{
    int i;
    float res;
    for(i=0;i<N;i++)
    {
	res = calc(a[i],b[i]);
    }
    return res;
}
