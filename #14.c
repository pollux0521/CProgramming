#include <stdio.h>

//ȭ���µ��� �Ǽ������� �Է¹޾� ��ȯ�ϴ� �Լ�
int get()
{
	int fahrenheit;
	printf("ȭ���µ�:");
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
