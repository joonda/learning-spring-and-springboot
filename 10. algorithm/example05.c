#include <stdio.h>

void showMenu()
{
	printf("**********ATM**********\n");
	printf("1. 입금(Deposit)\n");
	printf("2. 출금(Withdraw)\n");
	printf("3. 계좌 조회(Balance)\n");
	printf("4. 나가기(Exit)\n");
	printf("************************\n");
}

int main(void) {
	int choice;
	int balance = 0;
	int amount;

	while (1) {
		showMenu();
		printf("INPUT NUMBER 1~4 : ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("입금할 금액 : ");
			scanf_s("%d", &amount);
			balance += amount;
			printf("%d원 입금완료! \n", amount);
			printf("\n");
			break;
		case 2:
			printf("출금할 금액 : ");
			scanf_s("%d", &amount);
			if (amount > balance) {
				printf("잔액 부족 \n");
				printf("\n");
			}
			else {
				balance -= amount;
				printf("%d원 출금완료 ! \n", amount);
				printf("잔고 : %d원 \n", balance);
				printf("\n");
			}
			break;
		case 3:
			printf("잔액 조회 : %d원 \n", balance);
			printf("\n");
			break;
		case 4:
			printf("ATM을 종료합니다. \n");
			exit(0);
		default:
			printf("잘못된 선택입니다.  \n");
		}
	}
	return 0;
}