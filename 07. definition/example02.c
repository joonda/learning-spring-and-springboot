/* 소수 찾기 프로그램 */

#include <stdio.h>

int find_prime(int n) {
	int i;
	
	/* 소수는 1과 자기자신만을 약수로 갖는 수
	숫자 n을 기준으로, 2부터 n-1까지 나누어 떨어지는 수가 있다면 
	소수가 아니고 없다면 소수이다. */
	
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
		printf("%d는(은) 소수입니다.", num);
	}
	else {
		printf("%d는(은) 소수가 아닙니다.", num);
	}
}