#include <stdio.h>
#include <stdlib.h>

int money_operator(int total_money, int c_money) {
	if (total_money > c_money) {
		printf("%d���� ���ڶ��ϴ�,", abs(total_money - c_money));
	}
	else {
		printf("�Ž������� %d�� �Դϴ�.", c_money - total_money);
	}
	return 0;
}

int main(void) {
	int cus_money;
	int tot_money;

	printf("������ ���� ��ǰ ��ü �ݾ��� �Է����ּ���. : ");
	scanf_s("%d, %d", &cus_money, &tot_money);

	money_operator(tot_money, cus_money);

	return 0;
}