#include <stdio.h>

void display(int image[8][16]) {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 16; c++) {
			if (image[r][c] == 0) {
				printf("*");
			}
			else {
				printf("_");
			}
		}
		printf("\n");
	}
}

void inverse(int image[8][16]) {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 16; c++) {
			if (image[r][c] == 0) {
				image[r][c] = 1;
			}
			else {
				image[r][c] = 0;
			}
		}
	}
}

int main(void)
{
	int image[8][16] = {
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
   { 1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1 },
   { 1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1 },
   { 1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1 },
   { 1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
   { 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	printf("변환 전 이미지 \n");
	display(image);
	inverse(image);
	printf("\n\n변환 후 이미지 \n");
	display(image);
	return 0;
}