#include <stdio.h>

int number(int number)
{
	printf("������ �Է��Ͻÿ�:");
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
		printf("¦���Դϴ�."); 
	if(y = 1)
		printf("Ȧ���Դϴ�.");
	return 0;  
	
}
