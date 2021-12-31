#include <stdio.h>
int main(void)
{
	int i, years;
	double total, rate, investment;
	
	printf("원금:");
	scanf("%lf" , &investment);
	printf("이율(%%): ");
	scanf("%lf" , &rate);
	printf("기간(년): ");
	scanf("%d" , &years);
	
	printf("================");
	printf("연도 원리금\n");
	printf("================");
	total = investment;
	rate /= 100.0;
	for(i = 0; i < years; i++)
	{
		total = total * ( 1 + rate );
		printf("%2d %10.1f\n" , i+1, total);
		
	 } 
	 return 0;
}
