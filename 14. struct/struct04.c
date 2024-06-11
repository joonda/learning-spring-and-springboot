#include <stdio.h>

struct point {
	int x;
	int y;
};

int main(void) {
	struct point p1 = { 10, 20 };
	struct point p2 = { 30, 40 };

	// 대입 가능

	printf("p1.x & p1.y >> %d, %d \n", p1.x,p1.y );
	printf("p2.x & p2.y >> %d, %d \n", p2.x, p2.y);
	p2 = p1;
	printf("p1.x & p1.y >> %d, %d \n", p1.x, p1.y);
	printf("p2.x & p2.y >> %d, %d \n", p2.x, p2.y);

	// 비교는 구조체 내부의 원소끼리만 가능
	if ((p1.x == p2.x) && (p1.y == p2.y))
		printf("p1과 p2가 동일합니다. \n");

	return 0;
}