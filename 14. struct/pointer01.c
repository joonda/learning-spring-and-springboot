#include <stdio.h>

/* ���� ������ */

int main(void) {
	int i = 100;
	int* p = &i; // p�� i�� ����Ų��
	int** q = &p; // q�� ������ p�� ����Ű�� ���� ������

	*p = 200;
	printf("i = %d \n", i);

	**q = 300;
	printf("i = %d \n", i);

	return 0;
}