#include <stdio.h>

double c2f(double temp) {
	return temp * (9.0 / 5.0) + 32;
}

int main(void) {
	int temp;
	
	printf("¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf_s("%d", &temp);

	printf("¼·¾¾ ¿Âµµ %d´Â È­¾¾ ¿Âµµ %.3f ÀÔ´Ï´Ù.", temp, c2f(temp));

	return 0;
}