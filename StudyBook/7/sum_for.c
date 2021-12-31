//반복을 이용한 정수합 프로그램
#include <stdio.h>

int main(void)
{
	int i, sum;
	
	sum = 0;
	for(i = 1; i<= 10; i++)
		{
		
		sum += i;
		printf("현재 i=%d, sum=%d\n" , i , sum);
	}
	printf("1부터10까지의 정수의 합= %d\n" , sum);
	return 0;
 } 
