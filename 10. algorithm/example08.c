#include <stdio.h>

int hour_minute(int totalminute) {
	int hours = totalminute / 60;
	int minute = totalminute % 60;
	printf("%d�� >> %d�ð� %d�� \n", totalminute, hours, minute);
	return 0;
}

int main(void) {
	int minute;
	printf("���� �Է��ϼ���! : ");
	scanf_s("%d", &minute);

	hour_minute(minute);
	return 0;
}