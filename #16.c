#include <stdio.h>

double get_x()
{
	double silsu;
	printf("실수를 입력하시오.");
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
		
			printf("값이 음수입니다. 프로그램을종료합니다.");
			return 0; 
		}
		a = sigma(y , a);
		printf("총합 %lf" , a);  
	}
	return 0;
}
