#include <stdio.h>

int main(void)
{
	unsigned int color=0x00380000;  //픽셀의 색상 
	unsigned int result;
	
	printf("픽셀의 색상: %#08x\n" , color);
	result = color & 0x00ff0000;        //마스크연산 
	result = result >> 16;              //비트 이동 연산 
	printf("추출된 빨강색: %#08x\n" , result);
	return 0;
}

