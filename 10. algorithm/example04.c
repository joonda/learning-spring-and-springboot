/* 온도 변환 알고리즘 */
#include <stdio.h>

double c2f(double temp) {
	return temp * (9.0 / 5.0) + 32;
}

int main(void) {
	int temp;
	
	printf("섭씨 온도를 입력하세요. : ");
	scanf_s("%d", &temp);

	printf("섭씨온도 %d도는 화씨온도 %.3f 입니다.", temp, c2f(temp));

	return 0;
}