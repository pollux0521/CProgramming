#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random()
{
	int coin, x;
	printf("동전을 던집니다.\n");
	srand(time(NULL));
	coin = rand() % 2;
	return coin;
}

int minus(int x)
{
	if(x < 0)
		x = -x;
	return x;
}

int quiz(int x)
{
	int y;
	printf("짝수라 생각되면 1을 , 홀수라 생각되면 0을 입력하시오:\n");
	scanf(" %d" , &y);
	if(x == y)
		printf("정답입니다.\n");
 	if(x != y)
	 	printf("틀렸습니다.\n");
	return y; 
 } 
 
int main(void)
{
	int x , y , turn = 0;
	while(turn < 5)
	{
		x = random();
		minus(x);
		quiz(x);
		if(quiz(x) <= -1){
		
			printf("음수입니다. 종료합니다.\n");
			return 0; 
	}
		turn++;
	}
 	return 0;
 } 
