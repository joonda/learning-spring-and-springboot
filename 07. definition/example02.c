/* �Ҽ� ã�� ���� */

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
		printf("%d��(��) �Ҽ��Դϴ�", num);
	}
	else {
		printf("%d�� �Ҽ��� �ƴմϴ�", num);
	}
}