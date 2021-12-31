#include <stdio.h>
//매년 태양과 지구는 100km 씩 멀어진다고 가정할 때, 빛의 속도와 초기 태양과 지구간 거리를 입력받아 도달시간을 계산하는 함수
int noumugilu(double *distance , double *speed)
{
	double time;
	
	printf("초기 태양과 지구의 거리를 입력하시오:\n");
	scanf("%f" , distance);
	printf("빛의 속도를 입력하시오:\n");
	scanf("%f" , speed);
	time = *distance / *speed;
	printf("시간은 %f 초\n" , time); 
	return 0; 
 } 
 
 int years(double *distance , double *speed)
 {
 	int year=0;
 	double time;
	 while(year<100)
 	{
 		*distance = *distance + 100;
 		year++;
 		printf("%f distance " , *distance);	
 		time = *distance / *speed;
 		printf("도달 시간 %lf\n" , time);
 		
	 }
	return 0;
 }
 int main(void)
 {
 	double x , y;
	noumugilu(&x , &y);
	years(&x , &y);
	
	return 0;	
 }
