#include <stdio.h>
/* sum, i 모두 자동 변수
함수가 시작되면 생성되며 끝나면 소멸
함수 내에서 선언된 대부분의 변수가 auto 변수라고 할 수 있다.*/

int main(void) {
	auto int sum = 0;
	int i = 0;
}