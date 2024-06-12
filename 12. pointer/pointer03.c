#include <stdio.h>

int main(void)
{
	int i = 3000;
	int* p = NULL;

	p = &i;

	printf(" i = %d \n", i); // int i 
	printf(" &i = %u \n\n", &i); // &i 즉, 주소를 가지고 온다.
	printf(" *p = %d \n", *p); // 포인터 p로 i의 주소를 가지고 오는게 아닌, i의 값에 접근한다.
	printf(" p = %u \n", p); // i의 주소를 가지고 온다.

	return 0;
}