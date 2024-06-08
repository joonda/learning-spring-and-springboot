#include <stdio.h>

int main(void)
{
	int x;

	printf("변수 x의 크기 : %d byte\n", sizeof(x));
	printf("char형의 크기 : %d byte\n", sizeof(char));
	printf("int형의 크기 : % d byte\n", sizeof(int));
	printf("short형의 크기 : %d byte\n", sizeof(short));
	printf("long형의 크기 : % d byte\n", sizeof(long));
	printf("float형의 크기 : %d byte\n", sizeof(float));
	printf("double형의 크기 : %d byte\n", sizeof(double));

	return 0;
}