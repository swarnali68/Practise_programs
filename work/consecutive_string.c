#include <stdio.h>
#include <string.h>
#include "stack_lib.h"


void remove_consecutive_char(char* str)
{
	Node* head = NULL;
	int i = 0;
	int count = 0;
	int n = strlen(str);

	while(str[i] != '\0')
	{
		//data = str[i] - 'a';
		if((head != NULL) && (head->data == str[i]))	
		{
			pop(&head);
			count--;
		}
		else
		{
			push(&head, str[i]);
			count++;
		} 
		i++;
	}
	str[count] = '\0';

	while(count-- != 0)
	{
		str[count] = pop(&head);
	}
}

int main()
{
	char *str = NULL;

	str = (char *) malloc (sizeof(char) * 1024);

	printf("Enter the string");
	scanf("%s", str);

	remove_consecutive_char(str);

	printf("%s\n", str);

	free(str);

	return 0;
}
