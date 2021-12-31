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
 		printf("대문자입니다.");
 	 	if(x == 2)
 		printf("소문자입입니다.");
 	if(x == 3)
 		printf("숫자입니다.");
 	if(x == 4)
 		printf("기타문자입니다.");	
}
