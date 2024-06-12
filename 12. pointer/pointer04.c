#include <stdio.h>

int main(void)
{
    int x = 10, y = 20;
    int *p;

    p = &x;
    
    printf("p = %d \n", p);
    printf("p = %u \n", p);
    printf("*p = %d \n\n", *p);

    p = &y;
    printf("p = %d \n", p);
    printf("p = %u \n", p);
    printf("*p = %d \n\n", *p);

    return 0;
}