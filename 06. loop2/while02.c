// ���� ��� �� ���� ���ϱ�

#include <stdio.h>

int main(void) {
	int bacteria = 10;
	int hours = 0;

	while (hours < 7) {
		bacteria *= 4;
		hours++;
	}

	printf("7�ð� ���� ���� �� : %d \n", bacteria);

	return 0;
}