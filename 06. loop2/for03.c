#include <stdio.h>

int main(void) {
	int i, n;
	int factorial = 1;
	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		factorial *= i;
	}

	printf("%d!�� %d�Դϴ�.", n, factorial);

	return 0;
}