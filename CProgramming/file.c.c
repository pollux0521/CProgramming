#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FILE_NAME_SIZE 32

int main(void){
	int i;
	char data1[FILE_NAME_SIZE] = "a.txt";
	char data2[FILE_NAME_SIZE] = "b.txt";
	char buffer[FILE_NAME_SIZE];
	FILE* f_ptr;
	FILE* f2_ptr;

	f_ptr = fopen(data1, "r");
	fgets(buffer, FILE_NAME_SIZE, f_ptr);
	fputs(buffer, f_ptr);		//f_ptr �ȿ� �ִ� ���ڿ��� buffer �ȿ� ���� 
	printf("%s" , buffer);
	fclose(f_ptr);

	f2_ptr = fopen(data2, "w"); 
	fputs(buffer , f2_ptr);	   //buffer �ȿ� �ִ� ���ڿ��� b.txt�� ���� 
	fclose(f2_ptr);
	
	return 0;
}
