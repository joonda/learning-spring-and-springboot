#include <stdio.h>

double c2f(double temp) {
	return temp * (9.0 / 5.0) + 32;
}

int main(void) {
	int temp;
	
	printf("���� �µ��� �Է��ϼ��� : ");
	scanf_s("%d", &temp);

	printf("���� �µ� %d�� ȭ�� �µ� %.3f �Դϴ�.", temp, c2f(temp));

	return 0;
}