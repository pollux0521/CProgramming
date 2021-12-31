#include <stdio.h>
int get_x()
{
	int n;
	printf("숫자를 입력하시오\n");
	scanf("%d" , &n);
	return n;
}

int pandan(int n)
{
	int i;
	for(i = 0;  i < 1;  i++)
	{
		if(n % 2 == 1)
			continue;
		printf("정수\n %d" , n);
	}
	return 0;
}

int main(void)
{
	int x , i;
	for(i = 0; i < 10;  i++)
	{
		x = get_x();
		if(x <= -1)
			return 0;
		pandan(x);
		i++;
	}
	return 0;
}
