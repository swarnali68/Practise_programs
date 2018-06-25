#include <stdio.h>
#include <stdlib.h>

void reverseString(char* begin, char* end)
{
	while(begin < end)
	{
		*begin ^= *end;
		*end ^= *begin;
		*begin ^= *end;

		begin++;
		end--;
	}
}

void reverseWords(char* str)
{
	char *temp = str;
	char* beginWord = NULL;
	char* endWord = NULL;

	while(*temp)
	{
		beginWord = temp;

		while(*temp != ' ' && *temp != '\0')
		{
			temp++;
		}
		
		endWord = temp-1;

		reverseString(beginWord, endWord);
		if(*temp != '\0')
			temp++;
	}
	reverseString(str, temp-1);
}

int main()
{
	char* str;
	str = (char *) malloc (1024);

	printf("Enter the string you want to reverse");
	scanf("%[^\n]s", str);

	reverseWords(str);

	printf("%s\n",str);

	return 0;
}
