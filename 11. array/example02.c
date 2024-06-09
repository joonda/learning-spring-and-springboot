/* 최솟값 찾기 알고리즘 */

#include <stdio.h>

int main(void) {
	int arr[10] = { 28, 81, 60, 83, 67, 10, 66, 97, 37, 94 };
	int i;
	int minimum = arr[0];

	for (i = 1; i < 10; i++) {
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}

	printf("최소 값은 %d 입니다. ", minimum);

	return 0;
}