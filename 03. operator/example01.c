/*占쏙옙占쏙옙 占쏙옙占쏙옙 占쌌댐옙占쏙옙 占쏙옙 占쏙옙占쏙옙 占쌉뤄옙 占쌨곤옙,
占신쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占쏙옙求占� 占쏙옙占싸그뤄옙*/ 

#include <stdio.h>

int main(void) {
	int x, y;

	printf("占쏙옙占쏙옙 占쏙옙 占쌉뤄옙 : ");
	scanf_s("%d", &x);
	printf("占쏙옙占쏙옙占� 占쏙옙 占쏙옙 : ");
	scanf_s("%d", &y);

	int money = y - x;
	printf("占신쏙옙占쏙옙 占쏙옙 : %d占쏙옙 \n", money);

	printf("占쏙옙천占쏙옙 占쏙옙 : %d占쏙옙 \n", money / 5000);
	money %= 5000;
	printf("천占쏙옙 占쏙옙 : %d占쏙옙 \n", money / 1000);
	money %= 1000;
	printf("占쏙옙占쏙옙占� 占쏙옙占쏙옙 : %d占쏙옙 \n", money / 500);
	money %= 500;
	printf("占쏙옙占� 占쏙옙占쏙옙 : %d占쏙옙 \n", money / 100);
	money %= 100;

	return 0;
}