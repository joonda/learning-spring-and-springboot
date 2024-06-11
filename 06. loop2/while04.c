// 100만원 재테크 시작, 1년에 30% 수익
// 몇 년만에 원금의 10배가 되는지 게산하는 프로그램
#include <stdio.h>

int main(void) {
	int seed = 1000000;
	int year = 0;
	double final = seed;

	while (final < seed * 10) {
		final = final * 1.3;
		year++;
		printf("%d년 후 : %.0f원\n", year, final);
	}
	printf("원금의 10배가 되는 시점 >> %d년\n", year);

	return 0;
}


