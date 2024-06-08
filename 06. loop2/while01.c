// 방사능 물질의 반감기 확인하기
// 물질이 초기 값의 1/10이 되는 지점 구하기.

#include <stdio.h>

int main(void) {
	double initial, current;
	int year = 0;
	int halflife;

	printf("input halflife : ");
	scanf_s("%d", &halflife);

	initial = 100.0;
	current = initial;

	while (current > initial * 0.1) {
		year += halflife;
		current /= 2;
		printf("%d년 후 물질의 양 = %f \n", year, current);
	}

	printf("1/10 이하로 되기 까지 걸린 시간 = %d년", year);

	return 0;
}