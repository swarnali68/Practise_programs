#include <stdio.h>
#include <stdlib.h>

int convert(char* str)
{
	int n;
	int i = 0;
	int sign = 0;
	int offset = 0;

	if (str[0] == '-')
		sign = -1;

	if (sign == -1)
		offset = 1;

	for(i = offset; str[i] != '\0'; i++)
	{
		n = n*10 + str[i] - '0';
	}

	if(sign == -1)
		n = -n;

	return n;
}

int main()
{
	char *str = "str";
	int number;

	str = (char*) malloc (20); 

	printf("Enter the string you want to convert\n");
	scanf("%s", str);

	number = convert(str);

	printf("Converted Number: %d\n", number);

	return 0;
}
