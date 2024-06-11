// 반감기 >> 방사능 물질의 양이 1/2로 되는 시간
// 방사능 물질이 1/10 이하로 되기까지 걸리는 시간을 구하자.

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
		printf("%d년 후에 남은 양 = %f \n", year, current);
	}

	printf("1/10 이하로 되기 까지 걸린 시간 = %d년 \n", year);

	return 0;
}