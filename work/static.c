#include<stdio.h>

void fun()
{
	static int a;
}

int main()
{
	printf("%d",a);
	return 0;
}
