#include <stdio.h>
#include <conio.h> 
int main(void)
{
	int x, y;
	
	for (y = 1; y < 10000; y++)
	{
		for(x = 1; x < 50; x++)
		{
			if(_kbhit())    //Ű���带 ������ 1�� ��ȯ�Ѵ�. 
				goto OUT;
			printf("*");
		}
	printf("\n");	
	}
OUT:
	return 0;
}
