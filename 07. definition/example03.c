#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i;

	/* 시드 설정 일반적인 방법
	null 인자로 넘기면, 현재의 시간을 반환한다.
	즉, 실행마다 시간이 달라지기 때문에 
	고정값이 아닌 유동값을 얻을 수 있다.*/

	// srand >> 'seed random'

	srand((unsigned)time(NULL));

	for (i = 0; i < 6; i++) {
		printf("%d\n", 1 + (rand() % 45));
	}
	return 0;
}