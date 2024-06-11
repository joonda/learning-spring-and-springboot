#include <stdio.h>

int main(void)
{
	int x, y;

	printf("두 개의 정수를 입력하시오 : ");
	scanf_s("%d, %d", &x, &y);

	printf("%d && %d의 결과 값 : %d \n", x, y, x && y); // and
	printf("%d || %d의 결과 값 : %d \n", x, y, x || y); // or
	printf("!%d의 결과 값 : %d \n", x, !x); // not

	return 0;
}