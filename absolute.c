#include <stdio.h> 

int main (void)
{
    int n;
    int absolute;

    printf("정수 :");
    scanf_s("%d",&n);
    
    absolute = abs(n);
    printf("%d의 절대값:%d\n",n,absolute);

    return 0;
}
