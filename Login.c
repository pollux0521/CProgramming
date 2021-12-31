#include <stdio.h>
int main()
{
	int pass;
	char id;
	
	printf("아이디와 패스워드를 4개의 숫자로 입력하세요:\n");
	printf("id:____\b\b\b\b");
	scanf("%c" , &id);
	printf("pass:____\b\b\b\b");
	scanf("%d" , &pass);
	printf("\a입력된 아이디는 \"%c\" 이고 패스워드는 \"%d\"입니다. \n" , id, pass);
	return 0;
}
