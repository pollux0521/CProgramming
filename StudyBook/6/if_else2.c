#include <stdio.h>

int main(void)
{
	int n, d, result;
	
	printf("���ڸ� �Է��Ͻÿ�:");
	scanf("%d" ,&n);
	
	printf("�и� �Է��Ͻÿ�:");
	scanf("%d" , &d);
	
	if( d == 0 ) 
	{
		printf("0���δ� ������ �����ϴ�.\n");
	}
	else
	{
		result = n / d;
		printf("����� %d�Դϴ�." , result);
	
	}
	
	return 0; 
}
