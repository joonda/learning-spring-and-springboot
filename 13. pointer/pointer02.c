#include <stdio.h>

int main(void)
{
    int i = 10;
    int *pi = &i;

    printf("i = %d, pi = %p \n", i, pi);
    (*pi)++; /* 포인터 pi가 간접적으로 접근한 변수의 값을 증가 시킨다. */
    printf("i = %d, pi = %p \n", i, pi);

    printf("i = %d, pi = %p \n", i, pi);
    *pi++; /* pi가 가리키는 위치에서 값을 가져온 후, pi를 증가 시킨다. */
    printf("i = %d, pi = %p \n", i, pi);

    return 0;
}