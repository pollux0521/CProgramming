#include <stdio.h>

int get_x(int *number1 , int *number2)
{
	printf("������ �Է��Ͻÿ�:");
	scanf("%d" , number1);
	printf("������ �Է��Ͻÿ�:");
	scanf("%d" , number2);
	return 0;
}

int mok(int *number1 , int *number2)
{
	int x;
	x = *number1 / *number2;
	return x;
	
}
int namuzi(int *number1 , int *number2)
{
	int y;
	y = *number1 % *number2;
	return y;
}

int main(void)
{
	int x , y;
	get_x(&x , &y);
	if(y < 0){
		return 0;
}
	printf("���� %d" , mok(&x , &y));
	printf("�������� %d " , namuzi(&x , &y));
	return 0;
}
