#include <stdio.h>
#define TAX_RATE 0.2    //��ȣ������� 

int main(void)
{
	const int MONTHS = 12; //��ȣ������� 
	int m_salary, y_salary; //��������
	
	printf("������ �Է��Ͻÿ�:");
	scanf("%d" , &m_salary);
	
	y_salary = MONTHS*m_salary; //�����԰��
	printf("������ %d �Դϴ�.\n" , y_salary);
	printf("������ %f �Դϴ�.\n" ,  y_salary*TAX_RATE);
	
	return 0;
}