//���ڵ��� �з��ϴ� ���α׷�
#include <stdio.h>

int main(void)
{
	char ch;
	
	printf("���ڸ� �Է����ÿ�:");
	scanf("%c" , &ch);
	
	if( ch>= 'A' && ch<= 'Z')
		printf(" %c�� �빮���Դϴ�." , ch);
	else if( ch>= 'a' && ch<= 'z')
		printf(" %c�� �ҹ��� �Դϴ�." , ch);
	else if( ch>= '0' && ch<= '9')
		printf(" %c�� �����Դϴ�." , ch);
	else
		printf(" %c�� ��Ÿ�����Դϴ�." , ch);
} 
