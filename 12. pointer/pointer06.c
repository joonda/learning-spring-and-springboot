#include <stdio.h>

int main(void)
{
    int i;
    double db; /* 일반 double 변수 지정 */
    double *pd; /* 포인터 변수 지정 */

    pd = &db; /* db의 주소를 포인터 pd에 대입 */
    *pd = 36.5; // pd의 값을 포인터로 간접 접근하여 변경.

    printf("%f \n", db);
    printf("%f \n", *pd);
    printf("%u \n", &db);
    printf("%d \n", pd);
    printf("\n");

    return 0;
}