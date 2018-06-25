#include<stdio.h>
#include<string.h>

char* printString()
{
	char p[26];
	//char* str ;
	//char *p;
	strcpy(p, "abcdef");
	//printf("%s",p);
	//str = p;
	return (char*)p;
	//return "abcdef";	
}

int main()
{
	//char* str;
	//str = printString();
	//printf("%s",str);
	printf("%s\n",printString());
	//printString();
	return 0;
}
