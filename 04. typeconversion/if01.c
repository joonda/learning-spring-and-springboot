#include <stdio.h>
int main() {
	int i;
	printf("Input Numbers : ");
	scanf_s("%d", &i);

	if (i == 7) {
		printf("����� ����� ���� 7�� �Է��߽��ϴ�.");
	}
	else {
		printf("����� ���� %d�� �Է��߽��ϴ�.", i);
	}

	return 0;
}