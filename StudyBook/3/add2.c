// ����ڷκ��� �Է¹��� 2���� ������ ���� ����Ͽ� ���
#include <stdio.h>

int main(void)
{
	int x; 		//ù��° ������ ������ ����	 
	int y;		//�ι�° ������ ������ ���� 
	int sum;    // 2���� ������ ���� ������ ���� 
	
	printf("ù��° ������ �Է��Ͻÿ�:");  //�Է� �ȳ��޼��� ��� 
	scanf("%d\n" , &x);					  //�ϳ��� ������ �޾Ƽ� x�� ���� 
	
	printf("�ι�° ���ڸ� �Է��Ͻÿ�:");  //�Է� �ȳ��޼��� ��� 
	scanf("%d" , &y);                     //�ϳ��� ������ �޾Ƽ� y�� ����
	
	sum = x + y;                          //���� 2���� ���Ѵ� 
	printf("�μ��� ��: %d\n" , sum);		  //sum�� ���� 10���� ���·� ��� 
	
	
	return 0;			// 0�� �ֺη� ��ȯ 
	
	 
 } 