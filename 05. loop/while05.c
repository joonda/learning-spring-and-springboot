#include <stdio.h>

int main(void) {
	int i, n, sum;

	i = 0;
	sum = 0;
	while (i < 5) {
		printf("input number : ");
		scanf_s("%d", &n);
		sum = sum + n;
		i++;
	}

	printf("합계는 %d 입니다. \n", sum);

	return 0;
}