#include <stdio.h>

int main(void) {
	int num;

	printf("input number : ");
	scanf_s("%d", &num);

	if (num % 2 == 0) {
		printf("입력된 정수 %d는 짝수입니다.", num);
	}
	else {
		printf("입력된 정수 %d는 홀수입니다.", num);
	}

	return 0;
}