#include <stdio.h>

int grade()
{
	int grade;
	printf("input grade:\n");
	scanf("%d" , &grade);
	return grade;
}

int Letter_grade(int grade)
{
	if(grade >=90)
		printf("grade A");
	else if(grade >=80)
		printf("grade B");
	else if(grade >=70)
		printf("grade C");
	else if(grade >=60)
		printf("grade A");
	else if(grade <60)
		printf("grade F");
	return 0;
}
int main(void)
{
	int x;
	x = grade();
	Letter_grade(x);
	return 0;
}
