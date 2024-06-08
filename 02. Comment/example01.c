#include <stdio.h>
int main(void) {
	// 소수인 float으로 변수 설정
	float radius;
	float area;

	// scanf로 소수를 입력받는다.
	// %f로 float를 받는것. (부동소수점 수)
	printf("Input radius : ");
	scanf_s("%f", &radius);

	area = 3.141592 * radius * radius;
	printf("circle area : %f \n", area);

	return 0;
}