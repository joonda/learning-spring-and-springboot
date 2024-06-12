#include <stdio.h>

int main(void) {
	int arr[10];
	int i, ave=0;

	for (i = 0; i < 10; i++) {
		printf("%d 번째 학생의 성적은? ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	for (i = 0; i < 10; i++) {
		ave = ave + arr[i];
	}
	printf("전체 학생의 평균 : %d \n", ave/10);

	for (i = 0; i < 10; i++) {
		
		if (arr[i] >= ave/10) {
			printf("학생 %d : 합격 \n", i + 1);
		}
		else {
			printf("학생 %d : 불합격 \n", i + 1);
		}
	}
	return 0;
}