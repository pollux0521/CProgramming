/*���� ������ ���ϴ� ���α׷�*/
#include <stdio.h> 
 
int main(void) 
{
	float radius; //���� ������
	float area ;  // ����
	
	printf("�������� �Է��Ͻÿ�:");
	scanf("%f" , &radius);
	
	area = 3.14*radius*radius;
	
	printf("���� ����: %d" , area);
	
	return 0;    //��� �߸������ �˼� ����. 
}