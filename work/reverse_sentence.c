#include <stdio.h>
#include <stdlib.h>

void reverse(char* b, char* e)
{
	char tmp;
	while (b < e)
	{
		tmp = *b;
		*b = *e;
		*e = tmp;
		b++;
		e--;
	}
}

void reverse_sentence(char* str)
{
	char* beginword = NULL;
	char* endword   = NULL;
	char* tmp = str;

	while(*tmp)
	{
		if((beginword == NULL) && (*tmp != ' '))
		{
			beginword = tmp;
		}
		if(beginword && ((*(tmp+1) == '\0') || (*(tmp+1) == ' ')))
		{
			endword = tmp;
			reverse(beginword, endword);
			beginword = NULL;	
		}
		tmp++;
	}
	reverse(str, tmp-1);
}

int main()
{
	char *str = NULL;

	str = (char *) malloc (1024);

	printf("Enter the sentence to reverse: ");
	scanf("%[^\n]s", str);

	reverse_sentence(str);

	printf("After reversing: %s\n", str);
	
	return 0;
}
