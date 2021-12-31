#include <stdio.h>

int main(void)
{
	int i, n, sum;                   //변수선언 
	
	printf("정수를 입력하시오:");    //입력 안내 메세지 출력 
	scanf("%d" , &n);				 //정수값 입력
	
	i = 1;
	sum= 0;
	
	while(i <= n)
	{
		sum += i;    				  //sum = sum + i;와 같다. 
		i++;						  // i = i + 1;과 같다. 
	} 
	 printf("1부터 %d 까지의 합은 %d 입니다\n" , n, sum);
	 return 0; 
	 
 } 
