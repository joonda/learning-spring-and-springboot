/*복리 이자 계산 프로그램*/

#include <stdio.h>

int main(void) {
	float rate;
	double seed = 1000000.0;
	double total = seed;
	int years;

	printf("년 수를 입력하세요 : ");
	scanf_s("%d", &years);
	printf("이자율을 입력하세요 (ex > 0.05) : ");
	scanf_s("%f", &rate);

	for (int i = 1; i <= years; i++) {
		total = total * (1 + rate);
		printf("%d년 > %.0f원 \n", i, total);
	}
	
	return 0;
}