#include <stdio.h>

int main(void) {
	int usranswer;

	printf("��ǻ�Ͱ� ������ ���ڸ� ���� ������! : ");

	for (;;) {
		scanf_s("%d", &usranswer);
		if (usranswer == 3) {
			printf("���߼̱��� ! \n");
			break;
		}
		else {
			printf("Ʋ�Ⱦ�� ! \n");
		}
	}
	
	return 0;
}