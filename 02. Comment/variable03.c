#include <stdio.h>
#define TAX_RATE 0.2 // 기호 상수

int main(void)
{
	const int MONTHS = 12; // 기호 상수
	int m_salary, y_salary;

	printf("Input your salary : ");
	scanf_s("%d", &m_salary);
	y_salary = MONTHS * m_salary;
	printf("연봉은 %d 입니다.", y_salary);
	printf("세금은 %f 입니다. \n", y_salary * TAX_RATE);

	return 0;
}