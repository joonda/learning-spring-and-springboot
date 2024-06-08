#include <stdio.h>
int main() {
	int i;
	printf("Input Numbers : ");
	scanf_s("%d", &i);

	if (i == 7) {
		printf("당신은 행운의 숫자 7을 입력했습니다.");
	}
	else {
		printf("당신은 숫자 %d를 입력했습니다.", i);
	}

	return 0;
}