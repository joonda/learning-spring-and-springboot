#include <stdio.h>

int main(void) {
	int num;

	printf("input number : ");
	scanf_s("%d", &num);

	if (num % 2 == 0) {
		printf("�Էµ� ���� %d�� ¦���Դϴ�.", num);
	}
	else {
		printf("�Էµ� ���� %d�� Ȧ���Դϴ�.", num);
	}

	return 0;
}