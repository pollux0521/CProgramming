#include <stdio.h>
int month()
{
	int x;
	printf("달을 입력하시오\n");
	scanf("%d " , &x);
	return x; 
}

int pandan(int x)
{
		int days;	
		if(x = 2)
		{
			days = 28;
		}
		else if(x = 4)
		{
			days = 30;
		}
		else if(x = 6)
		{
			days = 30;	
		}
		else if(x = 9)
		{
			days = 30;
		}
		else if(x = 11)
		{
			days = 30;
			}
		else
		{
			days = 31;		
		}

	
	return days;
}
int main(void)
{
	int x , y;
	x = month();
	if(x <= -1)
	{
		return 0;
	}
	y = pandan(x);
	printf(" days = %d" , y);
	return 0;
}



