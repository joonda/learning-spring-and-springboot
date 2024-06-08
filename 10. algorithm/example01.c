/* 팩토리얼 계산 */

#include <stdio.h>

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	int num;
	printf("input number : ");
	scanf_s("%d", &num);
	printf("%d! >> %d", num, factorial(num));
	return 0;
}