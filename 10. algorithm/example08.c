#include <stdio.h>

int hour_minute(int totalminute) {
	int hours = totalminute / 60;
	int minute = totalminute % 60;
	printf("%d분 >> %d시간 %d분 \n", totalminute, hours, minute);
	return 0;
}

int main(void) {
	int minute;
	printf("분을 입력하세요! : ");
	scanf_s("%d", &minute);

	hour_minute(minute);
	return 0;
}