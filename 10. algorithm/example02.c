/* 3개의 정수를 입력 받아 최댓값을 구하는 것 */

#include <stdio.h>

int max(int x, int y, int z) {
	if (x > y && x > z) {
		return x;
	}
	else if (y > z) {
		return y;
	}
	else {
		return z;
	}
}

int main(void) {
	int x, y, z;

	printf("input numbers : ");
	scanf_s("%d, %d, %d", &x, &y, &z);
	printf("max number : %d \n", max(x, y, z));
	return 0;
}