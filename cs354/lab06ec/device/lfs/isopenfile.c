#include<xinu.h>

static bool8 isequalpath(char one[][LF_NAME_LEN], int len1, char two[][LF_NAME_LEN], int len2);

bool8 isopenfile(char pathTokens[][LF_NAME_LEN], int pathDepth, int*firstFreeSlot)
{
	struct lflcblk * lfptr;
	int i = 0;
	for (i = 0; i < Nlfl; i++)
	{
		lfptr = &lfltab[i];
		if (lfptr->lfstate == LF_FREE)
		{
			if (*firstFreeSlot == SYSERR)
			{
				*firstFreeSlot = i;
			}
		}
		else
		{
			if (isequalpath(lfptr->lfpath, lfptr->lfdepth, pathTokens, pathDepth))
			{
				signal(lfDirCblkMutex);
				return true;
			}
		}
	}

	return false;
}

static bool8 isequalpath(char one[][LF_NAME_LEN], int len1, char two[][LF_NAME_LEN], int len2)
{
	int i = 0;
	if (len1 != len2) return false;
	
	for(i = 0; i < len1; ++i)
	{
		if (!strcmp(one[i], two[i]))
		{
			return false;
		}
	}

	return true;
}
