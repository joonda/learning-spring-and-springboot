#include <stdio.h>

int main(void) {
	int month, day;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &month);
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &day);

	switch (month) {
	case 2:
		if (day >= 1 && day <= 28) {
			printf("��ȿ�� ��¥�Դϴ�.\n");
		}
		else {
			printf("��ȿ���� ���� ��¥�Դϴ�.\n");
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day >= 1 && day <= 30) {
			printf("��ȿ�� ��¥�Դϴ�.\n");
		}
		else {
			printf("��ȿ���� ���� ��¥�Դϴ�.\n");
		}
		break;
	default:
		if (day >= 1 && day <= 31) {
			printf("��ȿ�� ��¥�Դϴ�.\n");
		}
		else {
			printf("��ȿ���� ���� ��¥�Դϴ�.\n");
		}
		break;
	}
	return 0;
}