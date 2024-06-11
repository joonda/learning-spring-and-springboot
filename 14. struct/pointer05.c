#include <stdio.h>

/* 포인터를 통한 구조체 참조 */

struct student {
	int number;
	char name[50];
	float grade;
};

int main(void) {
	struct student s = { 24, "Kim", 4.3 };
	struct student* p;

	p = &s;

	printf("학번 >> %d, 이름 >> %s, 학점 >> %.1f \n", s.number, s.name, s.grade);
	printf("학번 >> %d, 이름 >> %s, 학점 >> %.1f \n", (*p).number, (*p).name, (*p).grade);
	printf("학번 >> %d, 이름 >> %s, 학점 >> %.1f \n", p->number, p->name, p->grade);

	return 0;
}
