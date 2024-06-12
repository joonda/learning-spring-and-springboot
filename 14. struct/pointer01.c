#include <stdio.h>

/* 이중 포인터 */

int main(void) {
	int i = 100; // int 형 변수
	int* p = &i; // p는 i를 가리키는 포인터
	int** q = &p; // q는 포인터 p를 가리키는 포인터

	*p = 200;
	printf("i = %d \n", i);

	**q = 300;
	printf("i = %d \n", i);

	return 0;
}