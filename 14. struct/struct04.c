#include <stdio.h>

struct point {
	int x;
	int y;
};

int main(void) {
	struct point p1 = { 10, 20 };
	struct point p2 = { 30, 40 };

	// ���� ����

	printf("p1.x & p1.y >> %d, %d \n", p1.x,p1.y );
	printf("p2.x & p2.y >> %d, %d \n", p2.x, p2.y);
	p2 = p1;
	printf("p1.x & p1.y >> %d, %d \n", p1.x, p1.y);
	printf("p2.x & p2.y >> %d, %d \n", p2.x, p2.y);

	// �񱳴� ����ü ������ ���ҳ����� ����
	if ((p1.x == p2.x) && (p1.y == p2.y))
		printf("p1�� p2�� �����մϴ�. \n");

	return 0;
}