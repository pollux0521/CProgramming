#include <stdio.h>

int get_n()
{
	int n;
	printf("������ �Է��Ͻÿ�:\n");
	scanf(" %d" , &n);
	return n;
}

int choidae(int x, int y)
{
	int ab ,r;
	for(ab = 0; y != 0; ab++)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main(void)
{
	int i, x, y;
	x = get_n();
	y = get_n();
	if(x < y)
	{
		i = x;
		x = y;
		y = i;
	}
	printf("�ִ������� %d �Դϴ�." , choidae(x , y));
	
		
}
