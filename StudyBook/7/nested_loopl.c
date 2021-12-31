//중첩 for문을 이용하여 *기호를 사각형 모양으로 출력하는 프로그램
#include <stdio.h>

int main(void)
{
	int x, y;
	
	for(y < 0; y < 5; y++)
	{
		for(x = 0;x < 10;x++)
			printf("*");
		
		printf("\n");  //내부반복문이 종료될 때마다 실행 
	}
	
	return 0;
 } 
