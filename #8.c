#include <stdio.h>
#define PI 3.141592

double get_x()
{
	double R;
	printf("반지릅을 입력하시오:");
	scanf("%lf" , &R);
	while(R<0){
	
		printf("다시입력하시오");
		scanf("%lf" , &R);
}
	return R; 
}
double area(double R)
{
	double area;
	area = R * R * PI;
	return area;
}

int main(void)
{
	double a , x = 0;
	while(x<5)
	{
	a = get_x();
	printf("넓이 = %lf " , area(a));
	x++;
	}
	return 0;
		
}
