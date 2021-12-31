#include <stdio.h>
#define EXCHANGE_RATE 1120

int dollar(int *usd)
{
	printf("달러를 입력하시오:");
	scanf("%d" , usd);
	return 0;
}

int won(int *usd)
{

	int krw;
	krw = EXCHANGE_RATE * *usd;
	return krw;
}

int main(void)
{
	int x , y;
	dollar(&x);
	y = won(&x);
	
	printf("달러화 금액은 %d원입니다." , y);
	return 0;
}
