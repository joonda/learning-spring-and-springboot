#include <stdio.h>

int addTwoNumbers(int a, int b) {
	return a + b;
}

int main() {
	int result = addTwoNumbers(3, 4);
	printf("Result > %d\n", result);
	return 0;
}