#include <stdio.h>

char get_input_c() {
	
	char ch;

	printf("Input Char:");
	scanf(" %c" , &ch);
	
	return ch;
}

int print_c(char a)
{
	printf("Char is %c" , a);	
	return 0;
}
int main(void)
{
	char c;
	int k=0;
	while(k<5){
	
	
    c = get_input_c();
	print_c(c);
	k++;
}
	
	return 0; 
}
