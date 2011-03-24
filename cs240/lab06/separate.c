
void separate(void **array, const int size, int(*separator)(const void *))
{
	void **tmp1;
	tmp1 = (void**)malloc(size * sizeof(void*));
	int c1 = 0;
	
	void **tmp2;
	tmp2 = (void**)malloc(size * sizeof(void*));
	int c2 = 0;
	
	int i;
	for (i = 0; i < size; i++)
	{
		if (separator(array[i]) == 0)
		{
			tmp1[c1] = array[i];
			c1++;
		}
		else
		{
			tmp2[c2] = array[i];
			c2++;
		}
	}
	
	if ((c1 + c2) != size)
	{
		printf("ERROR: Array dimension mismatch\n");
		exit(1);
	}
	
	int j;
	for (j = 0; j < c1; j++)
	{
		array[j] = tmp1[j];
	}
	for (j = c1; j < (c1 + c2); j++)
	{
		array[j] = tmp2[j - c1];
	}
}

int isalpha_separator(const void *arg)
{
	char *tmp;
	tmp = (char*)arg;
	
	if (((*tmp >= 'a') && (*tmp <= 'z')) ||
	    ((*tmp >= 'A') && (*tmp <= 'Z')))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int positiveInt_separator(const void *arg)
{
	int *tmp;
	tmp = (int*)arg;
	
	if (*tmp >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int iswholeDouble_separator(const void *arg)
{	
	double *tmp;
	tmp = (double*)arg;
	
	if (floor(*tmp) == *tmp)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
