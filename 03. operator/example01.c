#include <stdio.h>

int main(void) {
	int x, y;

	printf("물건 값을 입력하시오 : ");
	scanf_s("%d", &x);
	printf("사용자가 낸 돈 : ");
	scanf_s("%d", &y);

	int money = y - x;
	printf("거스름 돈 : %d원 \n", money);

	printf("오천원 권 : %d장 \n", money / 5000);
	money %= 5000;
	printf("천원 권 : %d장 \n", money / 1000);
	money %= 1000;
	printf("오백원 동전 : %d개 \n", money / 500);
	money %= 500;
	printf("백원 동전 : %d개 \n", money / 100);
	money %= 100;

	return 0;
}