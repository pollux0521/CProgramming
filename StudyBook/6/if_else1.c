// if���� ����Ͽ� Ȧ���� ¦���� �����ϴ� ���α׷�
#include <stdio.h>

int main(void)
{
	int number;
	
	printf("������ �Է��Ͻÿ�:");
	scanf("%d" , &number);
	
	if (number % 2 == 0)
		printf("�Էµ� ������ ¦���Դϴ�.\n");
	else 
		printf("�Էµ� ������ Ȧ���Դϴ�.\n");
		
	return 0; 
 } 