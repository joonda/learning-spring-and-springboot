#include <stdio.h>

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int main(void) {
	int x, y;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &x);

	printf("정수를 입력하시오 : ");
	scanf_s("%d", &y);

	int max_num = max(x, y);
	
	printf("최댓값은 > %d", max_num);
	return 0;
}