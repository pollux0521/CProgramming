#include <stdio.h>

int get_x(int *number1 , int *number2)
{
	printf("정수를 입력하시오:");
	scanf("%d" , number1);
	printf("정수를 입력하시오:");
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
	printf("몫은 %d" , mok(&x , &y));
	printf("나머지는 %d " , namuzi(&x , &y));
	return 0;
}
