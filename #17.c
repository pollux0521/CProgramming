#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random()
{
	int coin, x;
	printf("������ �����ϴ�.\n");
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
	printf("¦���� �����Ǹ� 1�� , Ȧ���� �����Ǹ� 0�� �Է��Ͻÿ�:\n");
	scanf(" %d" , &y);
	if(x == y)
		printf("�����Դϴ�.\n");
 	if(x != y)
	 	printf("Ʋ�Ƚ��ϴ�.\n");
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
		
			printf("�����Դϴ�. �����մϴ�.\n");
			return 0; 
	}
		turn++;
	}
 	return 0;
 } 
