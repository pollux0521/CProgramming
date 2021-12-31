//break를 이용하여 무한루프를 탈출한다
#include <stdio.h>
#include <math.h>

int main(void)
{
	double v;
	
	while(1)
	{
		printf("실수값을 입력하시오:");
		scanf("%lf" , &v);
		
		if(v <0.0)
			break;
		
		printf("%f의 제곱근은 %f입니다." , v, sqrt(v));   //sqrt()함수란 무엇인가??1111 
	}
	return 0; 
 } 
