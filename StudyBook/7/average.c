//while���� �̿��� ������ ��� ���ϱ� ���α׷�
#include <stdio.h>

int main(void)
{
	int grade, n;
	float sum, average;
	
	//�ʿ��Ѻ������� �ʱ�ȭ�Ѵ�.
	n = 0;
	sum = 0;
	grade = 0;
	
	printf("�����Ϸ��� ������ �Է��Ͻÿ�\n");
	
	//������ �Է¹޾Ƽ� �հ踦 ���ϰ� �л����� ���� 
	while (grade >=0)
	{
		printf("������ �Է��Ͻÿ�:");
		scanf("%d" , &grade);
		
		sum += grade;
		n++; 
	 } 
	 sum = sum - grade;
	 //����� ����ϰ� ȭ�鿡 ����Ѵ�.
	 average = sum / n;
	 printf("������ ����� %f�Դϴ�.\n" , average);
	 
	 return 0;
	 
 } 
