/* ������ �Է¹޾� ���� ���θ� üũ�ϴ� ���α׷� */

#include <stdio.h>

int Leapyear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	int year;
	printf("input year : ");
	scanf_s("%d", &year);
	if (Leapyear(year) == 1) {
		printf("%d���� �����Դϴ�. \n", year);
	}
	else {
		printf("%d���� ������ �ƴմϴ�. \n", year);
	}
}