/*���� ���� �մ��� �� ���� �Է� �ް�,
�Ž��� ���� ����ϴ� ���α׷�*/ 

#include <stdio.h>

int main(void) {
	int x, y;

	printf("���� �� �Է� : ");
	scanf_s("%d", &x);
	printf("����� �� �� : ");
	scanf_s("%d", &y);

	int money = y - x;
	printf("�Ž��� �� : %d�� \n", money);

	printf("��õ�� �� : %d�� \n", money / 5000);
	money %= 5000;
	printf("õ�� �� : %d�� \n", money / 1000);
	money %= 1000;
	printf("����� ���� : %d�� \n", money / 500);
	money %= 500;
	printf("��� ���� : %d�� \n", money / 100);
	money %= 100;

	return 0;
}