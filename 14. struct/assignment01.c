#include <stdio.h>

int main(void)
{
	// ������ ���� ����
	char* pc;
	int* pi;
	double* pd;

	// ������ �ּ� �� ����
	pc = (char*)1000;
	pi = (int*)1000;
	pd = (double*)1000;

	// ���� ��, �ּ� �� Ȯ��
	printf("���� �� pc = %d, pi = %d, pd = %d \n", pc, pi, pd);

	pc++;
	pi++;
	pd++;

	// ���� ��, �ּ� �� Ȯ��
	printf("���� �� pc = %d, pi = %d, pd = %d \n", pc, pi, pd);

	// +2 �� ���� �� �ּ� �� Ȯ��
	printf("pc+2 = %d, pi+2 = %d, pd+2 = %d \n", pc + 2, pi + 2, pd + 2);

	return 0;
}