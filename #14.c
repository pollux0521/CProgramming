#include <stdio.h>

//화씨온도를 실수형으로 입력받아 반환하는 함수
int get()
{
	int fahrenheit;
	printf("화씨온도:");
	scanf("%d" , &fahrenheit);
	
	 return fahrenheit;
 } 

int change(int fahrenheit)
{
	int celsius;
	celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
	return celsius;
}
int main(void)
{
	int a , b = 0;
	while(b<5)
	{
		a = get();
		printf("%d\n" ,change(a));
		
		b++;
	}
	return 0;
}
