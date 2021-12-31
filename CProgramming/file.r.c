#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FILE_NAME_SIZE 32
#define BUFFER_SIZE 32
int main(){
	char f_name[FILE_NAME_SIZE] = "b.txt";
	char buffer[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];
	FILE* f_ptr;
	int i = 0;
	int operand1, operand2;
	f_ptr = fopen(f_name, "r");
	fgets(buffer , BUFFER_SIZE, f_ptr);
	//fputs(buffer, f_ptr);
	int j = 0;
	for(i=0 , j=0; i<strlen(buffer); i++ , j++){
		if(isdigit(buffer[i])){
			tmp[j] = buffer[i];
		}
		else break;		
	}
	tmp[j] = '\0';
	operand1 = atoi(tmp);
	i++;
	printf(" %d\n" , operand1);
	for(j=0; i<strlen(buffer); i++, j++){
		if(isdigit(buffer[i])){
			tmp[j] = buffer[i];
		}
		else break;
	}
	tmp[j] = '\0';
	operand2 = atoi(tmp);
	printf(" %d" , operand2);
	fclose(f_ptr);
	
	return 0;
}
