#include <stdio.h>

int main(void)
{
	int x;

	printf("���� x�� ũ�� : %d byte\n", sizeof(x));
	printf("char���� ũ�� : %d byte\n", sizeof(char));
	printf("int���� ũ�� : % d byte\n", sizeof(int));
	printf("short���� ũ�� : %d byte\n", sizeof(short));
	printf("long���� ũ�� : % d byte\n", sizeof(long));
	printf("float���� ũ�� : %d byte\n", sizeof(float));
	printf("double���� ũ�� : %d byte\n", sizeof(double));

	return 0;
}