/* 주사위를 10,000번 던져서 각 면이 나오는 횟수를 출력하기 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int arr[6] = { 0, 0, 0, 0, 0, 0 };
	int i;

	srand(time(NULL)); 

	for (i = 0; i < 10000; i++) {
		++arr[rand() % 6];
	}

	for (i = 0; i < 6; i++) {
		printf("%d\t%d \n", i + 1, arr[i]);
	}

	return 0;
}