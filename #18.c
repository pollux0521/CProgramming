#include <stdio.h>

int max(int x, int y)
{
	printf("ū �� = %d\n" , (x > y)?  x : y);
	return 0;
}
int min(int x, int y)
{
	printf("���� �� = %d\n" , (x < y)?  x : y);
	return 0;
}

int main(void)
{
	int x , y;
	printf("ù��° �� :\n");
	scanf("%d" , &x); 
	printf("�ι�° �� :\n");
	scanf("%d" , &y);
	max(x , y);
	min(x , y);
	return 0;
} 
