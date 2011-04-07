#include <stdlib.h>
#include <stdio.h>

#define MAX_WORDS 5000
#define MAX_CHARS 50

char words[MAX_WORDS][MAX_CHARS];

char uniqueWords[MAX_WORDS][MAX_CHARS];
int wordCount[MAX_WORDS];

int isDelimeter(char c)
{
	if (c >= 'A' && c <= 'Z' ||
	    c >= 'a' && c <= 'z' ||
	    c >= '0' && c <= '9')
		return 0;
	else
		return 1;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage : %s <input file path>\n", argv[0]);
		exit(1);
	}	
	
	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error opening file: No such file or directory\n");
	}
	
	int wordCount;
	wordCount = 0;
	
	int charCount;
	charCount = 0;
	
	char *word;
	word = (char*)malloc(sizeof(char) * MAX_CHARS);
	
	char c;
	c = fgetc(fp);
	while (c != EOF)
	{
		if (isDelimeter(c) == 1)
		{
			if (charCount > 0)
			{
				word[charCount] = 0;
				charCount++;
			
				words[wordCount] = word;
				wordCount++;
			}
			
			word = (char*)malloc(sizeof(char) * MAX_CHARS);
			charCount = 0;
		}
		else
		{
			word[charCount] = c;
			charCount++;
		}
		
		c = fgetc(fp);
	}
	
	fclose(fp);
	
	printf("%d\n", wordCount);
	
	int i;
	for (i = 0; i < wordCount; i++)
	{
		printf("%s\n", words[i]);
	}
	
	exit(0);
}
