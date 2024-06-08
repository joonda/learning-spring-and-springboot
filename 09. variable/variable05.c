#include <stdio.h>

/* static은 정적 지역 변수로 지정할 수 있다. 
이는 프로그램 실행 시간 동안 지속되게 만듦. 
함수 호출 사이에 데이터를 유지해야할 때 사용 */

void sub() {
	static int scount = 0;
	int acount = 0;

	printf("scount = %d\t", scount);
	printf("acount = %d\n", acount);

	scount++;
	acount++;
}

int main(void) {
	sub();
	sub();
	sub();

	return 0;
}