#include <stdio.h>

// 구조체 설계
struct student {
	int number;
	char name[20];
	double grade;
};

int main(void) {
	// 구조체를 배열 형태로 선언 3차원 배열 (3*3 형태)
	struct student students[] = {
		{1001, "Andrew", 4.3},
		{1002, "Watson", 4.2},
		{1003, "Charlie", 4.1}
	};

	// 구조체 배열의 사이즈를 확인
	int size = sizeof(students) / sizeof(students[0]);


	// for loop를 사용하여 초기화된 정보 출력하기
	for (int i = 0; i < size; i++) {
		printf("Student %d \n", i + 1);
		printf("Number >> %d \n", students[i].number);
		printf("Name >> %s \n", students[i].name);
		printf("Grade >> %.2f \n", students[i].grade);
		printf("\n");
	}
	return 0;
}