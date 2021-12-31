
	
int main(void)
{
	int a, b ,c ,d;  
	return_value(&a, &b);    
	month(&a , &b);
	c = month(&a , &b);
	d = bokli(&a , &b);
	printf("%d\n" , c );
	printf("%d" , d);

	return 0;
}

int return_value(int *proper, int *sobi)
{
	printf("자본을 입력하시오:\n");
	scanf(" %d" , proper);
	printf("매달 소비 금액을 입력하시오:\n");
	scanf(" %d" , sobi);
 	return 0;
 } 
 
int month(int *proper , int *sobi)
{
	int year , c;
	year = *proper / (*sobi * 12);
	year++; 
	return year;
}

int bokli(int *proper , int *sobi)
{
	int years , c;
	while( c > 0 )
	{
	c = *proper - (*sobi * 12);
	years++;
	
	}
	return years;
}

