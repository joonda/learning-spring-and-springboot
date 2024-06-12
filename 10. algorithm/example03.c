/* 사용자 지정 함수 만들어서 진행하기 */

#include <stdio.h>

char find_grade(int score) {
	if (score >= 90) {
		return 'A';
	}
	else if (score >= 80) {
		return 'B';
	}
	else if (score >= 70) {
		return 'C';
	}
	else if (score >= 60) {
		return 'D';
	} else {
		return 'F';
	}
}

int main(void) {
	int score;
	printf("input score : ");
	scanf_s("%d", &score);
	printf("your score is %c \n", find_grade(score));
	return 0;
}