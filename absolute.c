#include <stdio.h> 

int main (void)
{
    int n;
    int absolute;

    printf("���� :");
    scanf_s("%d",&n);
    
    absolute = abs(n);
    printf("%d�� ���밪:%d\n",n,absolute);

    return 0;
}
