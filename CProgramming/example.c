#include <stdio.h>

int main(void){
	FILE *fp;
	int x, y;
	
	printf("�����Է� : ");
	scanf(" %d %d" , &x, &y); 
	
	
	fp = fopen("hello.txt" , "wt");
	if(fp == NULL){
		printf("����");
		return -1;
	}
	fprintf(fp ,"���� = %d" , x+y);
	fprintf(fp ,"���� = %d" , x-y);
	fprintf(fp ,"���� = %d" , x*y);
	fprintf(fp ,"������ = %d" , x/y);
	fclose(fp);
	
	printf("�Ϸ�");
	return 0;
	
}
