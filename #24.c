//while ���� �̿��� ������ ��� ���α׷�
#include <stdio.h>
int gugudan()
{
	int x;
	printf("����ϰ� ���� ���� �Է��Ͻÿ�.");
	scanf(" %d" , &x);
	return x;
 } 
 
int chul(int x)
{
	int i, gugu;
	for(i = 1; i < 10; i++)
	{
		gugu = i * x;
		printf("%d * %d = %d\n" , x , i , gugu);
	}
	return 0;
}

int main(void)
{
	int x = 1;
	while(x > 0)
	{
	x = gugudan();
		if(x < 0)
		{
			return 0;
		}
	chul(x);
	}
	return 0;
}
