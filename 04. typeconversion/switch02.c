// switch������ �ǵ����� break ����

#include <stdio.h>

int main(void) {
	int num;

	printf("input number : ");
	scanf_s("%d", &num);

	switch (num) {
	case 0:
		printf("����\n");
		break;
	case 1:
		printf("�ϳ�\n");
		break;
	case 2:
	case 3:
		printf("�� ����\n");
		break;
	default:
		printf("����\n");
		break;
	}

	return 0;
}