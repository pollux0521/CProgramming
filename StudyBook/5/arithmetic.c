#include <stdio.h>

int main()
{
	int x, y, result;
	
	printf("두개의 정수를 입력하시오:");
	scanf("%d %d" , &x, &y);
	
	result = x + y;		//덧셈연산 
	printf(" %d + %d = %d\n" , x, y, result);
	
	result = x - y;		//뼬샘연산 
	printf(" %d - %d = %d\n" , x, y, result);
	
	result = x * y;		//곱셈연산 
	printf(" %d * %d = %d\n" , x, y, result);
	
	result = x / y;		//나눗셈 연산 
	printf(" %d / %d = %d\n" , x, y, result);
	
	result = x % y;		//나머지연산 
	printf(" %d %% %d = %d\n" , x, y, result);
	
	return 0;	 
}
