// 100���� ����ũ ����, �� 30% ����
// �� �⸸�� ������ 10�谡 �Ǵ��� ���
#include <stdio.h>

int main(void) {
	int seed = 1000000;
	int year = 0;
	double final = seed;

	while (final < seed * 10) {
		final = final * 1.3;
		year++;
		printf("%d���� ���� : %.0f��\n", year, final);
	}
	printf("������ 10�谡 �Ǵµ� �ɸ� �ð�: %d��\n", year);

	return 0;
}


