// ���� ������ �ݰ��� Ȯ���ϱ�
// ������ �ʱ� ���� 1/10�� �Ǵ� ���� ���ϱ�.

#include <stdio.h>

int main(void) {
	double initial, current;
	int year = 0;
	int halflife;

	printf("input halflife : ");
	scanf_s("%d", &halflife);

	initial = 100.0;
	current = initial;

	while (current > initial * 0.1) {
		year += halflife;
		current /= 2;
		printf("%d�� �� ������ �� = %f \n", year, current);
	}

	printf("1/10 ���Ϸ� �Ǳ� ���� �ɸ� �ð� = %d��", year);

	return 0;
}