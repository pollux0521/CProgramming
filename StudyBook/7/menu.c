//do..while 문을 이용한 메뉴
#include <stdio.h>

int main(void)
{
	int i = 0;
	do
	{
		printf("1----새로파일만들기\n");
		printf("2----파일열기\n");
		printf("3----파일닫기\n");
		printf("하나를 선택하세요\n");
		scanf("%d" , &i);
		
	}while (1 <1 || 1>3);
	printf("선택된메뉴 = %d " , i);
	return 0;
 } 
