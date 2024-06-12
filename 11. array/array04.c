#include <stdio.h>

int main(void) {
	int arr[5];
	int i, ave = 0;

	// 학생들의 성적을 입력받는 부분
	for (i = 0; i < 5; i++) {
		printf("%d번째 학생의 성적은 ? : ", i+1);
		scanf_s("%d", &arr[i]);
	}

	// 성적의 총합을 구한다.
	for (i = 0; i < 5; i++) {
		ave = ave + arr[i];
	}

	// 평균이므로 5로 나누어준다.
	printf("전체 학생의 평균은 : %d \n", ave / 5);

	return 0;
}