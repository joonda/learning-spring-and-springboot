struct student {
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[100]; // struct�� �迭 ����

	list[2].number = 24;
	strcpy(list[2].name, "ȫ�浿");
	list[2].grade = 4.3;
}