#include <stdio.h>
#define SIZE 10
int main() 
{
	int arr[SIZE] = { 2, 10, 30, 21, 34, 23, 53, 21, 9, 1 };
	int i, j, temp, least;
	
	for (i = 0; i < SIZE; i++) {
		printf("배열의 %d 번째 원소 : %d \n", i + 1, arr[i]);
	}
	for (i = 0; i < SIZE-1; i++){
		least = i;
		for (j = i+1; j<SIZE; j++){
			if (arr[j] < arr[least]){
				least = j;
			}
			temp = arr[i];
			arr[i] = arr[least];
			arr[least] = temp;
		}
	}
	for (i=0; i<SIZE ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

