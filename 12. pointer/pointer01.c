/* ������ �ּ� ��� */

#include <stdio.h>

int main(void) {
	int i = 10;
	char c = 69;
	float f = 12.3;

	printf("i의 (%d) 주소 %u \n", i, &i);
	printf("c의 (%c) 주소 %u \n", c, &c);
	printf("f의 (%f) 주소 %u \n", f, &f);

	return 0;
}