#include <stdio.h>

int main(void) {
	int arr[10];
	int i, ave=0;

	for (i = 0; i < 10; i++) {
		printf("%d ��° �л��� ������ ? ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	for (i = 0; i < 10; i++) {
		ave = ave + arr[i];
	}

	for (i = 0; i < 10; i++) {
		if (arr[i] >= ave/10) {
			printf("�л� %d : �հ� \n", i + 1);
		}
		else {
			printf("�л� %d : ���հ� \n", i + 1);
		}
	}
	return 0;
}