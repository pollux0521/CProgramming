#include <stdio.h>

double get_x()
{
	double silsu;
	printf("�Ǽ��� �Է��Ͻÿ�.");
	scanf("%lf" , &silsu);
	return silsu;
}

double sigma(double silsu , double hap)
{
	hap = hap + silsu;
	return hap;
}

double minus(double silsu)
{
	if(silsu < 0.0)
		return 1;
}

int main(void)
{
	int x = 0;
	double y , z , a = 0.0;
	while(x<10)
	{
		y = get_x();
		if(y<0){
		
			printf("���� �����Դϴ�. ���α׷��������մϴ�.");
			return 0; 
		}
		a = sigma(y , a);
		printf("���� %lf" , a);  
	}
	return 0;
}
