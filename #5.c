#include <stdio.h>

char input()
{
	char ch;
	printf("input char:\n");
	scanf(" %c" , &ch);
	return ch;
}

int pandan(char ch)
{
	if(ch >='A' && ch <='Z')
		return 1; 
    if(ch >='a' && ch <='z')
		return 2;
	if(ch >='1' && ch <='9')
		return 3;
	else
		return 4;			 
}

int main(void)
{
 	int x;
	 char cha;
 	cha = input();
 	x = pandan(cha);
 	if(x == 1)
 		printf("�빮���Դϴ�.");
 	 	if(x == 2)
 		printf("�ҹ������Դϴ�.");
 	if(x == 3)
 		printf("�����Դϴ�.");
 	if(x == 4)
 		printf("��Ÿ�����Դϴ�.");	
}
