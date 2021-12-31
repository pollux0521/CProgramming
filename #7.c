#include <stdio.h>

int get_x(char *ch)
{
	printf("input char\n" );
	scanf(" %c" , ch);
	return 0;
}

int output(char *ch)
{
	printf(" ASCII Code is %d" , *ch);
	return 0;
}
int main(void)
{
	char ch;
	get_x(&ch);
	output(&ch);
	return 0;
}
