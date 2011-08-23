#include <sys/types.h>
#include <stdlib.h>

/*
 * Implement the following string procedures.
 *
 * Type "man strstr" to find what each of the functions should do.
 *
 * For example, mystrcpy should do the same as strcpy.
 *
 * IMPORTANT: DO NOT use predefined string functions.
 */

char *mystrcpy(char * s1, const char * s2)
{
	int i;
	i = 0;
	
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	
	s1[i] = '\0';
	
	return s1;
}

size_t mystrlen(const char *s)
{
	int i;
	i = 0;
	
	while(s[i] != '\0')
	{
		i++;
	}
	
	return i;
}

char *mystrdup(const char *s1)
{
	int len = mystrlen(s1) + 1;
	void *new = malloc(len);

  	return mystrcpy(new, s1);
}

char *mystrcat(char * s1, const char * s2)
{
	int len1 = mystrlen(s1) + 1;
	int len2 = mystrlen(s2) + 1;
	
	s1 = realloc(s1, len2);
	
	int i;
	for (i = len1; i < (len1 + len2); i++)
	{
		s1[i] = s2[len2 - i];
	}
	
	return s1;
}

char *mystrstr(char * s1, const char * s2)
{
	
}

int mystrcmp(const char *s1, const char *s2)
{
	
}

