#include <stdio.h>

int main(void)
{
	int x = 4;     //0100
	
	printf("��Ʈ << = %#08X\n" , x<<1);   //1000
	printf("��Ʈ >> = %#08X\n" , x<<1);  //0010
	
	return 0;
}
