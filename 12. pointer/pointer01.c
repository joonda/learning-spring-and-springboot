/* ������ �ּ� ��� */

#include <stdio.h>

int main(void) {
	int i = 10;
	char c = 69;
	float f = 12.3;

	printf("i�� (%d) �ּ� %u \n", i, &i);
	printf("c�� (%c) �ּ� %u \n", c, &c);
	printf("f�� (%f) �ּ� %u \n", f, &f);

	return 0;
}