#include<xinu.h>

int tokenize(char *path,char tokens[][LF_NAME_LEN])
{
	/* If name represents a single '/' return it*/
	int i = 0;
	int tokenCount = 0;
	if(path[i] == PATH_SEPARATOR && path[i+1] == '\0')
	{
		tokens[0][0] = '/';
		tokens[0][1] = '\0';
		return 1;
	}
	int index = 0;
	
	while(tokenCount < LF_PATH_DEPTH)
	{
		if(path[index] == PATH_SEPARATOR)
		{
			++index;
		}
		for(i=0;path[index]&&path[index]!=PATH_SEPARATOR&&i<LF_NAME_LEN-1;++i)
		{
			tokens[tokenCount][i]=path[index];	
			++index;
		}
		if(i)
		{
			if(i >= LF_NAME_LEN-1)
			{
				return SYSERR;
			}
			tokens[tokenCount][i] = '\0';
			++tokenCount;
			
		}
		if(path[index] == NULLCH || (path[index] == PATH_SEPARATOR && path[index+1] == NULLCH))
		{
			break;
		}
	}
	return tokenCount;
}
