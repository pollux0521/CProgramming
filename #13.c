#include <stdio.h>
//�ų� �¾�� ������ 100km �� �־����ٰ� ������ ��, ���� �ӵ��� �ʱ� �¾�� ������ �Ÿ��� �Է¹޾� ���޽ð��� ����ϴ� �Լ�
int noumugilu(double *distance , double *speed)
{
	double time;
	
	printf("�ʱ� �¾�� ������ �Ÿ��� �Է��Ͻÿ�:\n");
	scanf("%f" , distance);
	printf("���� �ӵ��� �Է��Ͻÿ�:\n");
	scanf("%f" , speed);
	time = *distance / *speed;
	printf("�ð��� %f ��\n" , time); 
	return 0; 
 } 
 
 int years(double *distance , double *speed)
 {
 	int year=0;
 	double time;
	 while(year<100)
 	{
 		*distance = *distance + 100;
 		year++;
 		printf("%f distance " , *distance);	
 		time = *distance / *speed;
 		printf("���� �ð� %lf\n" , time);
 		
	 }
	return 0;
 }
 int main(void)
 {
 	double x , y;
	noumugilu(&x , &y);
	years(&x , &y);
	
	return 0;	
 }
