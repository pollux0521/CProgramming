#include <stdio.h>

int main(void)
{
	int usd; //�޷�ȭ
	int krw; //��ȭ
	
	printf("�޷�ȭ �ݾ��� �Է��Ͻÿ�:" );
	scanf("%d" &usd);
	
	krw = 1120*usd;
	
	printf("�޷�ȭ %d �޷��� %d ���Դϴ�.\n" , usd , krw);
	
	return 0; 
}
