#include <stdio.h>

int main(void) {
	int arr[5];
	int i, ave = 0;

	// ����ڷκ��� �л����� ������ �Է� ����
	for (i = 0; i < 5; i++) {
		printf("%d ��° �л��� ������? : ", i+1);
		scanf_s("%d", &arr[i]);
	}

	// �л����� ������ ���� ���Ѵ�.
	for (i = 0; i < 5; i++) {
		ave = ave + arr[i];
	}

	// ��� �� ���ϱ�
	printf("��ü �л��� ��� : %d \n", ave / 5);

	return 0;
}