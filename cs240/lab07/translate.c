#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_CHARS 50

char words[MAX_WORDS * 5][MAX_CHARS];

char uniqueWords[MAX_WORDS][MAX_CHARS];
int uniqueWordsCount[MAX_WORDS] = { 0 };

int isDelimeter(char c)
{
	if (c >= 'A' && c <= 'Z' ||
	    c >= 'a' && c <= 'z' ||
	    c >= '0' && c <= '9')
		return 0;
	else
		return 1;
}

int indexInArray(int length, char* search)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        int match = 0;
        
        int j;
        j = 0;
        while (uniqueWords[i][j] != 0)
        {
            if (uniqueWords[i][j] == search[j])
            {
                match = 1;
            }
            else
            {
                match = 0;
                break;
            }
            
            j++;
        }
        
        if (match == 1)
            return i;
    }
    
    return -1;
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
			
				strcpy(words[wordCount], word);
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

    int uniqueWordsCountCount;
    uniqueWordsCountCount = 0;
    
    int i;
    for (i = 0; i < wordCount; i++)
    {
        int x;
        x = indexInArray(wordCount, words[i]);
        
        if (x >= 0)
        {
            uniqueWordsCount[x]++;
        }
        else
        {
            strcpy(uniqueWords[uniqueWordsCountCount], words[i]);
            uniqueWordsCount[uniqueWordsCountCount]++;
            
            uniqueWordsCountCount++;
        }
    }
    
    for (i = 0; i < uniqueWordsCountCount; i++)
    {
        printf("<%d> %s %d\n", i + 1, uniqueWords[i], uniqueWordsCount[i]);
    }
    
    fp = fopen("output.txt", "w");
    
    char buffer[MAX_WORDS * MAX_CHARS];
    
    for (i = 0; i < wordCount; i++)
    {
        fprintf(fp, "<%d>", indexInArray(wordCount, words[i]) + 1);
    }
        
    fclose(fp);
}
