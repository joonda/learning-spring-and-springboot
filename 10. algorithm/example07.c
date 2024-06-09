/* 연도를 입력받아 윤년 여부를 체크하는 프로그램 */

#include <stdio.h>

int Leapyear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	int year;
	printf("input year : ");
	scanf_s("%d", &year);
	if (Leapyear(year) == 1) {
		printf("%d년은 윤년입니다. \n", year);
	}
	else {
		printf("%d년은 윤년이 아닙니다. \n", year);
	}
}