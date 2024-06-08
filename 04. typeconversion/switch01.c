// switch 문
// case 에서 변수, 변수가 들어간 수식, 실수, 문자, 문자열은 사용할 수 없다

#include <stdio.h>

int main(void) {
	int num;

	printf("input number : ");
	scanf_s("%d", &num);

	switch (num) {
	case 0:
		printf("없음\n");
		break;
	case 1:
		printf("하나\n");
		break;
	case 2:
		printf("둘\n");
		break;
	default:
		printf("많음\n");
		break;
	}
	
	return 0;
}