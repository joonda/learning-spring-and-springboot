#include <stdio.h>

/* �迭�� ���� Ÿ���� ����, 
����ü�� ���� �ٸ� Ÿ�� ���� ���� �Բ� ���� �� �ִ�. */


struct student {
	int number;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s;
	s.number = 20190001;
	strcpy(s.name, "ȫ�浿");
	s.grade = 4.3;

	printf("�й� > %d \n", s.number);
	printf("�̸� > %s \n", s.name);
	printf("���� > %.1f \n", s.grade);
}