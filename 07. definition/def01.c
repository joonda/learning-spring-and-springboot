/*print_stars 함수, 아무것도 반환하지 않는다.*/

#include <stdio.h>

void print_stars()
{
	for (int i = 0; i < 30; i++) {
		printf("*");
	}
}

int main(void) {

	print_stars();

	return 0;
}