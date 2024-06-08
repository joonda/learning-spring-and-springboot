// switch문에서 의도적인 break 생략

#include <stdio.h>

int main(void) {
	int num;

	printf("input number : ");
	scanf_s("%d", &num);

	switch (num) {
	case 0:
		printf("없음\n");
		break;
	case 1:
		printf("하나\n");
		break;
	case 2:
	case 3:
		printf("두 세개\n");
		break;
	default:
		printf("많음\n");
		break;
	}

	return 0;
}