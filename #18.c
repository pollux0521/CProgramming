#include <stdio.h>

int max(int x, int y)
{
	printf("큰 수 = %d\n" , (x > y)?  x : y);
	return 0;
}
int min(int x, int y)
{
	printf("작은 수 = %d\n" , (x < y)?  x : y);
	return 0;
}

int main(void)
{
	int x , y;
	printf("첫번째 수 :\n");
	scanf("%d" , &x); 
	printf("두번째 수 :\n");
	scanf("%d" , &y);
	max(x , y);
	min(x , y);
	return 0;
} 
