#include <stdio.h>

int main(void)
{
	int x , y;
	printf("�� ���� ������ �Է��Ͻÿ�:");
	scanf("%d%d" , &x , &y);
	
	printf("%d && %d�� ����� : %d\n"  , x, y, x&&y); //AND����
	printf("%d || %d�� �����: %d\n" , x, y, x||y);   //or ���� 
	printf("!%d�� �����: %d\n" , x, !x);                  //NOT ���� 
	
	return 0; 
}
