#include <stdio.h>

/* add, sub 함수 원형을 미리 정의 */
int add(int, int);
int sub(int, int);

int main(void) 
{
	int result; 
	int (*pf)(int, int); // 함수 포인터 정의

	pf = add; // 함수 포인터 pf를 add로 초기화
	result = pf(10, 20); // 10과 20을 넣어서 연산 진행
	printf("10 + 20 >> %d \n", result);

	pf = sub; // 함수 포인터 pf를 sub로 초기화
	result = pf(10, 20); // 10과 20을 넣어서 연산 진행
	printf("10 - 20 >> %d \n", result);

	return 0;
}
/* 앞의 함수 원형을 추후에 정의 진행 */
int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}
