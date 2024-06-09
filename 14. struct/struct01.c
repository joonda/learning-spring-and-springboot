#include <stdio.h>

/* 배열은 같은 타입의 변수, 
구조체는 서로 다른 타입 변수 등을 함께 묶을 수 있다. */


struct student {
	int number;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s;
	s.number = 20190001;
	strcpy(s.name, "홍길동");
	s.grade = 4.3;

	printf("학번 > %d \n", s.number);
	printf("이름 > %s \n", s.name);
	printf("학점 > %.1f \n", s.grade);
}