// 세균 배양 후, 숫자 구하기

#include <stdio.h>

int main(void) {
	int bacteria = 10;
	int hours = 0;

	while (hours < 7) {
		bacteria *= 4;
		hours++;
	}

	printf("7시간 후의 세균 수 : %d \n", bacteria);

	return 0;
}