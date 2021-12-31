#include <stdio.h>

int random()
{
	int x;
	srand(time(NULL));
	x = rand() % 11;
	return x;
}

int input()
{
	int n;
	printf("추측해보시오:\n");
	scanf(" %d" , &n);
	return n; 
}

int compare(int x , int y)
{
	if(x > y)
		{
		return 1;
		}
	if(x < y)
		{
		return -1;
		}
	if(x == y)
		{
		return 0;
		}
}
int main(void)
{
	int x , y , z;
	x = random();
	y = input();
	printf("%d" , x);
	if(y < 0)
	{
		return 0;
	}
	while(x != y)
	{
		z = compare(x , y);
		if(z == 1)
			{
			printf("입력값이 작습니다.");
			}
		if(z == -1)
			{
			printf("입력한 값이 큽니다."); 
	 		}
		y = input();
	 } 
	return 0;
}



