#include <stdio.h>

// ����ü ����
struct student {
	int number;
	char name[20];
	double grade;
};

int main(void) {
	// ����ü�� �迭 ���·� ���� 3���� �迭 (3*3 ����)
	struct student students[] = {
		{1001, "Smith", 4.32},
		{1002, "Lawrence", 4.21},
		{1003, "Vanessa", 3.98}
	};

	// ����ü �迭�� ����� Ȯ��
	int size = sizeof(students) / sizeof(students[0]);


	// for loop�� ����Ͽ� �ʱ�ȭ�� ���� ����ϱ�
	for (int i = 0; i < size; i++) {
		printf("Student %d \n", i + 1);
		printf("Number >> %d \n", students[i].number);
		printf("Name >> %s \n", students[i].name);
		printf("Grade >> %.2f \n", students[i].grade);
		printf("\n");
	}
	return 0;
}