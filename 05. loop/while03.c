#include <stdio.h>

int main(void) {
	int i, n, sum;
	printf("input number : ");
	scanf_s("%d", &n);

	i = 1;
	sum = 0;

	while (i <= n) {
		sum += i;
		i++;
	}

	printf("1부터 %d까지의 합은 %d입니다 \n", n, sum);
	return 0;
}