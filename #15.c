#include <stdio.h>
//change 거스름돈
// 

//투입한 돈 , 물건값 , 거스름돈을 입력받아 반환하는 함수 
int get_coins(int *coins, int *change)
{
	int price , money;
	printf("투입한 돈:\n");
	scanf("%d" , &money);
	printf("물건값:\n");
	scanf("%d" , &price);
	*change = money - price;
	return 0;   
}



//거스름돈에서 100원짜리 개수와 나머지 거스름돈을 계산하는 함수 
int calc_100change(int *coins, int *change)
{
	*coins = *change/100;
	*change = *change%100;
	printf("100원짜리 = %d\n" , *coins);
	printf("거스름돈 = %d\n" , *change);	
	return 0; 
}
//거스름돈에서 10원짜리의 개수 계산 
int calc_10change(int *coins , int *change)
{
	printf("현재coins값=%d , change값 = %d\n" , *coins , *change);
	*change = *change/10;
	printf("10원짜리 = %d\n" , *change);
	return 0;
}
int main()
{
	int x , y;
	get_coins(&x, &y);
	calc_100change(&x , &y);
	calc_10change(&x , &y);
	

	return 0;
	
}
