/* 3가지 정수를 입력 받고 그 중 최댓값 찾기 */

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
	printf("max number : %d", max(x, y, z));
	return 0;
}