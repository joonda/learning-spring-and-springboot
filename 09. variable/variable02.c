#include <stdio.h>
/* global variable ���� */
int A;
int B;
int counter;

int add()
{
	return A + B;
}

int main()
{
	int answer;
	A = 5;
	B = 7;
	answer = add();
	printf("%d + %d = %d\n", A, B, answer);

	/* ���������� �����Ϸ��� ���α׷� ���� ��, 0���� �ʱ�ȭ */
	printf("counter = %d \n", counter);

	return 0;
}