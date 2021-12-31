#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	system("dir");				
	printf("아무 키나 누르세요\n");
	getch(); //??? system getch() 함수란?
	system("cls");
	
	return 0; 
	
}
