#include <stdio.h>

int main(void) {
	double math, science, english, programming;
	
	printf("4���� ������ ������ �Է��ϼ���. : ");
	scanf_s("%lf, %lf, %lf, %lf", &math, &science, &english, &programming);
	
	double avg = (math + science + english + programming) / 4;

	if (avg >= 90) {
		printf("����� �����Դϴ�.");
	}
	else if (avg >= 30 && avg < 90) {
		printf("���ݸ� ����ϼ���!");
	}
	else if (avg == 0) {
		printf("���θ� �߷��մϱ� ?");
	}
	else {
		printf("�� ������ �ϼ���!");
	}

	return 0;
}