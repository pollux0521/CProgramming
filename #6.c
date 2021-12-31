#include <stdio.h>

char get_x()
{
	char ch;
	printf("input char\n" );
	scanf("%c" , &ch);
	return ch;
}

int char_(char ch)
{
	printf("in %c" , ch);
	return 0;
}
int main(void)
{
	char x;
	x = get_x();
	char_(x);
	return 0;
}
