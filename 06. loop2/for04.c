#include <stdio.h>

int main(void) {
	int usranswer;

	printf("컴퓨터가 생각한 숫자를 맞춰보세요 ! : ");

	for (;;) {
		scanf_s("%d", &usranswer);
		if (usranswer == 3) {
			printf("맞추셨군요 ! \n");
			break;
		}
		else {
			printf("틀렸어요 ! \n");
		}
	}
	
	return 0;
}