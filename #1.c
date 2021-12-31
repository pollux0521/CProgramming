#include <stdio.h>

int number()
{
	int number;
	printf(" 정수를 입력하시오:");
	scanf("%d" , &number);
	return number;
}

int Judg(int x)
{
	if(x %2 == 0)
	{
		printf("Even number");
	}
	else
	{
		printf("Odd number");
	}
}


int main(void)
{
	int k;
	k = number();
	Judg(k);
	return 0;
}

