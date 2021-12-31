#include <stdio.h>

int main(void)
{
	int i = 1, k = 1 , l = 1;
	while (i <=9)
	{
		while(k <=9)
		{
			

			printf("%d X %d = %d\n" , i, k, i*k);
			k++;
		}
		i++;
		k = 1;
		
			}
	return 0;
}
