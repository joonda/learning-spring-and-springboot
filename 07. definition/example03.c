#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i;

	/* �õ� ���� �Ϲ����� ���
	null ���ڷ� �ѱ��, ������ �ð��� ��ȯ�Ѵ�.
	��, ���ึ�� �ð��� �޶����� ������ 
	�������� �ƴ� �������� ���� �� �ִ�.*/

	// srand >> 'seed random'

	srand((unsigned)time(NULL));

	for (i = 0; i < 6; i++) {
		printf("%d\n", 1 + (rand() % 45));
	}
	return 0;
}