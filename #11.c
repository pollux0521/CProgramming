#include <stdio.h>

int year()
{
	int year;
	printf("�Ⱓ�� �Է��Ͻÿ�:");
	scanf("%d" , &year);
	return year;
	
}
int get_money()
{
	int get;
	printf("���� �ݾ��� �Է��ϼ���_:");
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
		printf("%d�� ���� ��� = %d��\n" , a , b);
		c++;
		
	}
	printf("%d�� ���� ��� = %d��\n" , a , b);
	return 0;
}
