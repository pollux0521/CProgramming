#include <stdio.h>

int year()
{
	int year;
	printf("기간을 입력하시오:");
	scanf("%d" , &year);
	return year;
	
}
int get_money()
{
	int get;
	printf("저축 금액을 입력하세요_:");
	scanf("%d" , &get);
	return get; 
}

int property(int bok , int property)
{
	int x = 0 , y = 0;
	while(x < bok)
	{
		y = (y + property* 12) * 1.05;
		x++;
	} 
	return y;
}

int main(void)
{
	int a , b , c=0;
	while(c <3){

	a = year();
	b = get_money();
	
	
		b = property(a , b);
		printf("%d년 후의 재산 = %d원\n" , a , b);
		c++;
		
	}
	printf("%d년 후의 재산 = %d원\n" , a , b);
	return 0;
}
