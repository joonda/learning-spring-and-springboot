#include <stdio.h>

int main(void) {
	int i, n;
	int factorial = 1;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		factorial *= i;
	}

	printf("%d!은 %d입니다.", n, factorial);

	return 0;
}