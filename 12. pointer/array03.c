/* 행렬 간 덧셈 */

#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void) {
	int A[ROWS][COLS] = { {2, 3, 0},
		{8,9,1}, {7,0,5} };

	int B[ROWS][COLS] = { {1, 0, 0},
		{1,0,0}, {1,0,0} };

	int C[ROWS][COLS];

	int r, c;
	for(r=0; r<ROWS; r++)
		for (c = 0; c < COLS; c++) {
			C[r][c] = A[r][c] + B[r][c];
		}

	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			printf("%d ", C[r][c]);
		}
		printf("\n");
	}

	return 0;
}