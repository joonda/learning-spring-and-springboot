#include <stdio.h>
#define TAX_RATE 0.2 // ��ȣ ���

int main(void)
{
	const int MONTHS = 12; // ��ȣ ���
	int m_salary, y_salary;

	printf("Input your salary : ");
	scanf_s("%d", &m_salary);
	y_salary = MONTHS * m_salary;
	printf("������ %d �Դϴ�.", y_salary);
	printf("������ %f �Դϴ�.", y_salary * TAX_RATE);

	return 0;
}