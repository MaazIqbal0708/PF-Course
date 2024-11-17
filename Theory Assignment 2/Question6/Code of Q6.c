//q6
#include<stdio.h>
int match(int n)
{
    if (n%5==0) 
	{
        return -1;
    }
	else
	{
        return n%5;
    }
}
int main()
{ 
    int n;
	printf("Enter the number of matches: ");
	scanf("%d", &n);
	match(n);
	int result=match(n);
    if (result==-1) 
	{
        printf("Return -1");
    }
	else
	{
        printf("A should pick %d matchstick(s).\n", result);
    }
}
