#include <stdio.h>
//change �Ž�����
// 

//������ �� , ���ǰ� , �Ž������� �Է¹޾� ��ȯ�ϴ� �Լ� 
int get_coins(int *coins, int *change)
{
	int price , money;
	printf("������ ��:\n");
	scanf("%d" , &money);
	printf("���ǰ�:\n");
	scanf("%d" , &price);
	*change = money - price;
	return 0;   
}



//�Ž��������� 100��¥�� ������ ������ �Ž������� ����ϴ� �Լ� 
int calc_100change(int *coins, int *change)
{
	*coins = *change/100;
	*change = *change%100;
	printf("100��¥�� = %d\n" , *coins);
	printf("�Ž����� = %d\n" , *change);	
	return 0; 
}
//�Ž��������� 10��¥���� ���� ��� 
int calc_10change(int *coins , int *change)
{
	printf("����coins��=%d , change�� = %d\n" , *coins , *change);
	*change = *change/10;
	printf("10��¥�� = %d\n" , *change);
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
