#include <stdio.h>
#define FILE_NAME_SIZE 32
#define BUFFER_SIZE 32
int main(){
	char f_name[FILE_NAME_SIZE] = "a.txt";
	char buffer[BUFFER_SIZE] = "I am 9root\n";
	FILE* f_ptr;
	
	f_ptr = fopen(f_name, "a");
	fputs(buffer, f_ptr);
	//fprintf(f_ptr, "%s" , buffer);
	fclose(f_ptr);
	
	return 0;
}
