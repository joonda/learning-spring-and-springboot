#include <stdio.h>

int main(void){
    float a = 3.141592;
    double b = 3.141592;

    printf("float형의 크기 : %d byte\n", sizeof(a));
	printf("double형의 크기 : %d byte\n", sizeof(b));

    printf("a : %f \n", a);
    printf("b : %f \n", b);


    return 0;
}