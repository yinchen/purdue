#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPresent (char *mainString, char *subString);

/******************************************************************************
 * main() function
 ******************************************************************************/

int main(int argc, char **argv){

	if (argc != 2) // (argc < 2)
	{
		printf("Usage : mygrep {String to Search} <{File Name}\n");
		exit(0);
	}

	char search[256];
	strcpy(search, "");
	
	int i;
	for (i = 1; i < argc; i++)
	{
		strcat(search, argv[i]);
		
		if (i != (argc - 1))
			strcat(search, " ");
	}
	
	char file[256];
	strcpy(file, "");
	
	while (gets(file) != NULL)
	{
		if (isPresent(file, search) == 1)
		{
			printf("%s\n", file);
		}
	}
}

/******************************************************************************
 * isPresent() function
 ******************************************************************************/

int isPresent (char *mainString, char *subString){

	int i;
	for (i = 0; i < strlen(mainString); i++)
	{
		int j, z;
		for (j = 0; j < strlen(subString); j++)
		{
			if (mainString[i + j] != subString[j])
			{
				z = 0;
				break;
			}
			else
			{
				z = 1;
			}
		}
		
		if (z == 1)
			return 1;
	}
	
	return 0;
}
