#include <stdio.h>

int main(void)
{
	int n, d, result;
	
	printf("분자를 입력하시오:");
	scanf("%d" ,&n);
	
	printf("분모를 입력하시오:");
	scanf("%d" , &d);
	
	if( d == 0 ) 
	{
		printf("0으로는 나눌수 없습니다.\n");
	}
	else
	{
		result = n / d;
		printf("결과는 %d입니다." , result);
	
	}
	
	return 0; 
}
