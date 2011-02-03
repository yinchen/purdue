#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *string);

/******************************************************************************
 * main() function
 ******************************************************************************/

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage : reverse <string>\n");
		exit(0);
	}
	
	char string[256];
	strcpy(string, "");
	
	int i;
	for (i = 1; i < argc; i++)
	{
		strcat(string, argv[i]);
		
		if (i != (argc - 1))
			strcat(string, " ");
	}
	
	printf("Reverse of String = ");
	reverse(string);
	printf("\n");
}

/******************************************************************************
 * reverse() function using recursion
 ******************************************************************************/

void reverse(char *string)
{
	if (*string != '\0')
	{
		reverse(string + 1);
	}
	else
	{
		return;
	}	
	
	printf("%c", *string);
}
