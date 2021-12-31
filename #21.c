#include <stdio.h>

int get_x()
{
	int x;
	printf("가로의 크기를 정수로 입력하시오:\n");
	scanf(" %d" , &x);
	return x;
	
}

int get_y()
{
	int y;
	printf("세로의 크기를 입력하시오:\n");
	scanf("%d" , &y);
	return y;
}

int length_x(int x)
{
	int i = 0;
	while(i < x)
	{
		printf("*");
		i++;
	}
	printf("\n");
	return 0;
}

int length_y(int x , int y)
{
	int i = 0, garo = 0;
	while(i < y-2)
	{
		printf("*");
		garo = 0;
		while(garo < x-2)
	  		{
			  printf(" ");
			  garo++;
	 		}
	 	printf("*");		 	
	 	printf("\n");
	 	i++;
	  }  
	  return 0;
	
	
}

int main(void)
{
	int x , y;
	x = get_x();
	y = get_y();
	length_x(x);
	length_y(x , y);
	length_x(x);
	return 0;
}

