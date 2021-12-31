#include <stdio.h>

int number(int number)
{
	printf("정수를 입력하시오:");
	scanf("%d" , &number);
	return number;
}

int pandan(int number)
{
	if(number % 2 == 0)
		return 0;
	if(number % 2 == 1)
		return 1;
}

int main(void)
{
	int x , y , z;
	x = number(z);
	y = pandan(x);
	if(y = 0)
		printf("짝수입니다."); 
	if(y = 1)
		printf("홀수입니다.");
	return 0;  
	
}
