#include <stdio.h>

void showMenu()
{
	printf("**********ATM**********\n");
	printf("1. �Ա�(Deposit)\n");
	printf("2. ���(Withdraw)\n");
	printf("3. ���� ��ȸ(Balance)\n");
	printf("4. ������(Exit)\n");
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
			printf("�Ա��� �ݾ� : ");
			scanf_s("%d", &amount);
			balance += amount;
			printf("%d�� �ԱݿϷ�! \n", amount);
			printf("\n");
			break;
		case 2:
			printf("����� �ݾ� : ");
			scanf_s("%d", &amount);
			if (amount > balance) {
				printf("�ܾ� ���� \n");
				printf("\n");
			}
			else {
				balance -= amount;
				printf("%d�� ��ݿϷ� ! \n", amount);
				printf("�ܰ� : %d�� \n", balance);
				printf("\n");
			}
			break;
		case 3:
			printf("�ܾ� ��ȸ : %d�� \n", balance);
			printf("\n");
			break;
		case 4:
			printf("ATM�� �����մϴ�. \n");
			exit(0);
		default:
			printf("�߸��� �����Դϴ�.  \n");
		}
	}
	return 0;
}