#include <stdio.h>

int main(void) {
	int num1, num2;
	char operator;

	printf("�� ���� ������ ������ �� ���� �Է��ϼ��� ! : ");
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
			printf("0���� ���� �� �����ϴ�. \n");
		}
		break;
	default:

		printf("�߸��� �Է��Դϴ�. \n");
	}
	return 0;
}