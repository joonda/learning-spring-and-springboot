#include <stdio.h>

int main(void) {
	int score;

	printf("Input score : ");
	scanf_s("%d", &score);

	if (score >= 90) {
		printf("����� �հ��Դϴ�!");
	}

	else {
		printf("����� ���հ��Դϴ�!");
	}
	return 0;
}