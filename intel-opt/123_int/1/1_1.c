#include <stdio.h>

extern void unknown(int *a);

int main()
{
    int a,b,c;

    a=5;
    c=a;
    unknown(&a);
    if(a==5) 
    printf("a==5\n");
    b=a;
    printf("%d %d %d\n",a,b,c);
    return(1);
}
