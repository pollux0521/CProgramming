#include <stdio.h>

int id_pass(int *id , int *pass)
{
	printf("int id:____\b\b\b\b\n");
	scanf("%d" , id);
	printf("int pw:____\b\b\b\b\n");
	scanf("%d" , pass);
	return 0;
}

int equal(int *id, int *pass)
{
	if(*id == *pass)
		printf("RE\n");

	
	return 0;
}

int output(int *id , int *pass)
{
	printf("input id is %d , pass is %d" , *id , *pass);
	return 0;
}
int main(void)
{
	int x, y , z = 0 , w  ;
	
	while(z<5)
	{
		id_pass(&x , &y);
		while(&x == &y);
		{
		equal(&x , &y);
		output(&x , &y);
		z++;
	
		}
	}
	return 0;
}
