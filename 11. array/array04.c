#include <stdio.h>

int main(void) {
	int arr[5];
	int i, ave = 0;

	// 사용자로부터 학생들의 성적을 입력 받음
	for (i = 0; i < 5; i++) {
		printf("%d 번째 학생의 성적은? : ", i+1);
		scanf_s("%d", &arr[i]);
	}

	// 학생들의 성적을 전부 합한다.
	for (i = 0; i < 5; i++) {
		ave = ave + arr[i];
	}

	// 평균 값 구하기
	printf("전체 학생의 평균 : %d \n", ave / 5);

	return 0;
}