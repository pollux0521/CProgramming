//�ݺ��� �̿��� ������ ���α׷�
#include <stdio.h>

int main(void)
{
	int i, sum;
	
	sum = 0;
	for(i = 1; i<= 10; i++)
		{
		
		sum += i;
		printf("���� i=%d, sum=%d\n" , i , sum);
	}
	printf("1����10������ ������ ��= %d\n" , sum);
	return 0;
 } 
