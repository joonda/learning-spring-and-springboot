/* 소수 찾기 예제 */

#include <stdio.h>

int find_prime(int n) {
	int i;

	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
		return 1;
	}
}

int main(void) {
	int num;
	printf("input number : ");
	scanf_s("%d", &num);

	int count = find_prime(num);
	if (count == 1) {
		printf("%d은(는) 소수입니다", num);
	}
	else {
		printf("%d는 소수가 아닙니다", num);
	}
}