#include <stdio.h>
#include <conio.h> 
int main(void)
{
	int x, y;
	
	for (y = 1; y < 10000; y++)
	{
		for(x = 1; x < 50; x++)
		{
			if(_kbhit())    //키보드를 눌르면 1을 반환한다. 
				goto OUT;
			printf("*");
		}
	printf("\n");	
	}
OUT:
	return 0;
}
