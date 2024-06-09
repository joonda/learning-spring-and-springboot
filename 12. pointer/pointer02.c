#include <stdio.h>

int main(void)
{
	int i = 10; // 정수형 변수 i 선언
	double f = 12.3;

	int* pi = NULL;
	double* pf = NULL;
	
	pi = &i;
	pf = &f;

	printf("%u %u \n", pi, &i);
	printf("%u %u \n", pf, &f);

	return 0;
}