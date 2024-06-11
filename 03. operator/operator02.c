#include <stdio.h>

int main(void) {
	int x = 10, y = 10;

	printf("x = %d \n", x);
	printf("++x = %d \n", ++x); // 먼저 증가 후 수식에 사용
	printf("x = %d \n", x);

	printf("y = %d \n", y);
	printf("y++ = %d \n", y++); // 현재 값을 수식에 사용 후, 나중에 증가
	printf("y = %d \n", y);
	
	return 0;
}