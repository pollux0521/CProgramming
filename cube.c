#include <stdio.h>

int my_fac() {
	int x=0;
	int y=0;
	 scanf("%d" , &x);
	 
	 while (y<1){
	 	y = y+1;
	 	x = x*x*x;
	 }
		printf("%d" , x);
	return 0;
}

int main() {
	my_fac();
	
	return 0;
}
