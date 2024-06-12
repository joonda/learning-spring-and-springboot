#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getSensorData(double* p)
{
	srand(time(NULL));

	p[0] = rand() % 100;
	p[1] = rand() % 100;
	p[2] = rand() % 100;
	return;
}

int main(void){
	double sensorData[3];
	getSensorData(sensorData);

	printf("왼쪽 센서와 장애물과의 거리 : %f \n", sensorData[0]);
	printf("중간 센서와 장애물과의 거리 : %f \n", sensorData[1]);
	printf("오른쪽 센서와 장애물과의 거리 : %f \n", sensorData[2]);	
	
	return 0;
}