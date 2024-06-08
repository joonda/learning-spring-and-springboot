#include <stdio.h>

int main(void) {
	int score;

	printf("Input score : ");
	scanf_s("%d", &score);

	if (score >= 90) {
		printf("당신은 합격입니다!");
	}

	else {
		printf("당신은 불합격입니다!");
	}
	return 0;
}