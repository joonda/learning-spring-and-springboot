#include <stdio.h>

/* �����͸� ���� ����ü ���� */

struct student {
	int number;
	char name[50];
	float grade;
};

int main(void) {
	struct student s = { 24, "Kim", 4.3 };
	struct student* p;

	p = &s;

	printf("�й� >> %d, �̸� >> %s, ���� >> %.1f \n", s.number, s.name, s.grade);
	printf("�й� >> %d, �̸� >> %s, ���� >> %.1f \n", (*p).number, (*p).name, (*p).grade);
	printf("�й� >> %d, �̸� >> %s, ���� >> %.1f \n", p->number, p->name, p->grade);

	return 0;
}
