#include <stdio.h>
#define EXCHANGE_RATE 1120

int dollar(int *usd)
{
	printf("�޷��� �Է��Ͻÿ�:");
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
	
	printf("�޷�ȭ �ݾ��� %d���Դϴ�." , y);
	return 0;
}
