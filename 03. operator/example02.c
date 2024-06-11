#include <stdio.h>

int main(void){
    double light = 300000;
    double distance = 149600000;
    
    printf("빛의 속도는 %lf km/s \n", light);
    printf("태양과 지구와의 거리는 %lf km \n", distance);
    printf("도달 시간은 %lf 분 \n", (distance/light)/60);

    return 0;
}