#include <stdio.h>
int main(void) {

	float radius;
	float area;

	printf("Input radius : ");
	scanf_s("%f", &radius);

	area = 3.141592 * radius * radius;
	printf("circle area : %f \n", area);

	return 0;
}