#include <stdio.h>

int main(void) {
	int x = 10, y = 10;

	printf("x = %d \n", x);
	printf("++x = %d \n", ++x); // ���� ���� �� ���Ŀ� ���
	printf("x = %d \n", x);

	printf("y = %d \n", y);
	printf("y++ = %d \n", y++); // ���� ���� ���Ŀ� ��� ��, ���߿� ����
	printf("y = %d \n", y);
	
	return 0;
}