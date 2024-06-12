#include <stdio.h>

int main(void) {
	int num1, num2;
	char operator;

	printf("두 개의 정수와 연산자를 입력해주세요 ! : ");
	scanf_s("%d, %d, %c", &num1, &num2, &operator);
	
	switch (operator) {
	case '+':
		printf("%d + %d = %d \n", num1, num2, num1 + num2);
		break;
	case '-':
		printf("%d - %d = %d \n", num1, num2, num1 - num2);
		break;

	case '*':
		printf("%d * %d = %d \n", num1, num2, num1 * num2);
		break;
	case '/':
		if (num2 != 0) {
			printf("%d / %d = %d \n", num1, num2, num1 / num2);
		}
		else {
			printf("0으로 나눌 순 없습니다. \n");
		}
		break;
	default:

		printf("잘못된 입력입니다. \n");
	}
	return 0;
}