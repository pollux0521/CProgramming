//��øfor���� �̿��Ͽ� *��ȣ�� �簢�� ������� ����ϴ� ���α׷�
#include <stdio.h>
int main(void)
{
	int x, y;
	for(y = 1; y < 5; y++)
	{
		for(x = 0; x < y; x++)
			printf("*");
		
		printf("\n");		//���� �ݺ����� ����� ������ ���� 
	}
	return 0;
 } 
