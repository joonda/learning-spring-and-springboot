#include <stdio.h>

int main(void)
{
	int x, y;

	printf("�� ���� ������ �Է��Ͻÿ� : ");
	scanf_s("%d, %d", &x, &y);

	printf("%d && %d�� ��� �� : %d \n", x, y, x && y); // and
	printf("%d || %d�� ��� �� : %d \n", x, y, x || y); // or
	printf("%!%d�� ��� �� : %d \n", x, !x); // not
}