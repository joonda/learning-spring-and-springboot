#include <stdio.h>

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int main(void) {
	int x, y;
	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &x);

	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &y);

	int max_num = max(x, y);
	
	printf("�ִ� �� > %d", max_num);
	return 0;
}