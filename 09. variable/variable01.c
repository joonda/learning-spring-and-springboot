#include <stdio.h>

int main(void) {
	int i;

	for (i = 0; i < 5; i++) {

		// temp를 지속적으로 1로 초기화 진행
		// 지역 변수 temp
		int temp = 1;
		printf("temp = %d\n", temp);
		temp++;
	}
	return 0;
}