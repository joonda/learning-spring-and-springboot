#include <stdio.h>

int main(void) {
	double math, science, english, programming;
	
	printf("4가지 과목의 점수를 입력하세요. : ");
	scanf_s("%lf, %lf, %lf, %lf", &math, &science, &english, &programming);
	
	double avg = (math + science + english + programming) / 4;

	if (avg >= 90) {
		printf("당신은 우등생입니다.");
	}
	else if (avg >= 30 && avg < 90) {
		printf("조금만 노력하세요!");
	}
	else if (avg == 0) {
		printf("공부를 발로합니까 ?");
	}
	else {
		printf("더 열심히 하세요!");
	}

	return 0;
}