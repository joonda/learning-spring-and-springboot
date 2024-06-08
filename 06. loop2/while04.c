// 100만원 재테크 시작, 연 30% 수익
// 몇 년만에 원금의 10배가 되는지 계산
#include <stdio.h>

int main(void) {
	int seed = 1000000;
	int year = 0;
	double final = seed;

	while (final < seed * 10) {
		final = final * 1.3;
		year++;
		printf("%d년차 수익 : %.0f원\n", year, final);
	}
	printf("원금의 10배가 되는데 걸린 시간: %d년\n", year);

	return 0;
}


