/*원의 면적을 구하는 프로그램*/
#include <stdio.h> 
 
int main(void) 
{
	float radius; //원의 반지름
	float area ;  // 면적
	
	printf("반지름을 입력하시오:");
	scanf("%f" , &radius);
	
	area = 3.14*radius*radius;
	
	printf("원의 면적: %d" , area);
	
	return 0;    //어디가 잘못됬는지 알수 없음. 
}
