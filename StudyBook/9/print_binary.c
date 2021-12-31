//2진수 형식으로 출력
#include <stdio.h>
void print_binary(int x);

int main(void)
{
	print_binary(9);
	return 0;
	
}
void print_binary(int x)
{
	if ( x > 0)
	{
		print_bianary(x / 2);
		printf("%d" , x % 2);
	}
}
