#include <stdio.h>
#include <stdlib.h>

int money_operator(int total_money, int c_money) {
	if (total_money > c_money) {
		printf("%d원이 모자랍니다,", abs(total_money - c_money));
	}
	else {
		printf("거스름돈은 %d원 입니다.", c_money - total_money);
	}
	return 0;
}

int main(void) {
	int cus_money;
	int tot_money;

	printf("지불할 돈과 물품 전체 금액을 입력해주세요. : ");
	scanf_s("%d, %d", &cus_money, &tot_money);

	money_operator(tot_money, cus_money);

	return 0;
}