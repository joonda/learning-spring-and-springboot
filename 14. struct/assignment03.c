#include <stdio.h>

/* add, sub �Լ� ������ �̸� ���� */
int add(int, int);
int sub(int, int);

int main(void) 
{
	int result; 
	int (*pf)(int, int); // �Լ� ������ ����

	pf = add; // �Լ� ������ pf�� add�� �ʱ�ȭ
	result = pf(10, 20); // 10�� 20�� �־ ���� ����
	printf("10 + 20 >> %d \n", result);

	pf = sub; // �Լ� ������ pf�� sub�� �ʱ�ȭ
	result = pf(10, 20); // 10�� 20�� �־ ���� ����
	printf("10 - 20 >> %d \n", result);

	return 0;
}
/* ���� �Լ� ������ ���Ŀ� ���� ���� */
int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}
