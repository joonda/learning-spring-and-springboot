#include <stdio.h>
int main(void) {
	// �Ҽ��� float���� ���� ����
	float radius;
	float area;

	// scanf�� �Ҽ��� �Է¹޴´�.
	// %f�� float�� �޴°�. (�ε��Ҽ��� ��)
	printf("Input radius : ");
	scanf_s("%f", &radius);

	area = 3.141592 * radius * radius;
	printf("circle area : %f \n", area);

	return 0;
}