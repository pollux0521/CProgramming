#include <stdio.h>
int main()
{
	int pass;
	char id;
	
	printf("���̵�� �н����带 4���� ���ڷ� �Է��ϼ���:\n");
	printf("id:____\b\b\b\b");
	scanf("%c" , &id);
	printf("pass:____\b\b\b\b");
	scanf("%d" , &pass);
	printf("\a�Էµ� ���̵�� \"%c\" �̰� �н������ \"%d\"�Դϴ�. \n" , id, pass);
	return 0;
}
