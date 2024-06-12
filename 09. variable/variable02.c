#include <stdio.h>
/* global variable 지정 */
int A;
int B;
int counter;

int add()
{
	return A + B;
}

int main()
{
	int answer;
	A = 5;
	B = 7;
	answer = add();
	printf("%d + %d = %d\n", A, B, answer);

	/* 전역변수는 컴파일러가 프로그램 실행 시, 0으로 초기화 */
	printf("counter = %d \n", counter);

	return 0;
}