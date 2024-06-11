struct student {
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[100]; // struct의 배열 선언

	list[2].number = 24;
	strcpy(list[2].name, "홍길동");
	list[2].grade = 4.3;
}