#include <stdio.h>
int get_x()
{
	int n;
	printf("���ڸ� �Է��Ͻÿ�\n");
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
		printf("����\n %d" , n);
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
