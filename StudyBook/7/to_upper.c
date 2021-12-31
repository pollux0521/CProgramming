//소문자를 대문자로 변경한다
#include <stdio.h>

int main(void)
{
	char letter;
	
	while(1)
	{
		printf("소문자를 입력하시오:");
		scanf(" %c", &letter); //공백외의 문자 
		
		if( letter == 'Q')
			break;
		if( letter < 'a' || letter > 'z')
			continue;
		
		letter -= 32;
		printf("변환된 대문자는 %c 입니다.\n" , letter);
		 
	}
	
	return 0;
 } 
