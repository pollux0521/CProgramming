#include <stdio.h>

int main(void){
	FILE *fp;
	int x, y;
	
	printf("¼ýÀÚÀÔ·Â : ");
	scanf(" %d %d" , &x, &y); 
	
	
	fp = fopen("hello.txt" , "wt");
	if(fp == NULL){
		printf("½ÇÆÐ");
		return -1;
	}
	fprintf(fp ,"µ¡¼À = %d" , x+y);
	fprintf(fp ,"»¬¼À = %d" , x-y);
	fprintf(fp ,"°ö¼À = %d" , x*y);
	fprintf(fp ,"³ª´°¼À = %d" , x/y);
	fclose(fp);
	
	printf("¿Ï·á");
	return 0;
	
}
