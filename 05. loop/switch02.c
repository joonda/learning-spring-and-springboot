#include <stdio.h>

int main(void) {
	int month, day;
	printf("월을 입력하세요 : ");
	scanf_s("%d", &month);
	printf("일을 입력하세요 : ");
	scanf_s("%d", &day);

	switch (month) {
	case 2:
		if (day >= 1 && day <= 28) {
			printf("유효한 날짜입니다.\n");
		}
		else {
			printf("유효하지 않은 날짜입니다.\n");
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day >= 1 && day <= 30) {
			printf("유효한 날짜입니다.\n");
		}
		else {
			printf("유효하지 않은 날짜입니다.\n");
		}
		break;
	default:
		if (day >= 1 && day <= 31) {
			printf("유효한 날짜입니다.\n");
		}
		else {
			printf("유효하지 않은 날짜입니다.\n");
		}
		break;
	}
	return 0;
}