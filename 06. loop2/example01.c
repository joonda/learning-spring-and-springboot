/*���� ���� ��� ���α׷�*/

#include <stdio.h>

int main(void) {
	float rate;
	double seed = 1000000.0;
	double total = seed;
	int years;

	printf("�� ���� �Է��ϼ��� : ");
	scanf_s("%d", &years);
	printf("�������� �Է��ϼ��� (ex > 0.05) : ");
	scanf_s("%f", &rate);

	for (int i = 1; i <= years; i++) {
		total = total * (1 + rate);
		printf("%d�� > %.0f�� \n", i, total);
	}
}