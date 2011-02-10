#include <stdio.h>
#include <string.h>
#include <math.h>

int bcd_encode(int i, int n, char *s)
{
	int index;
	index = 1;
	while (i != 0)
	{
		s[index] = (i % 10) + 48;
		i = i / 10;
		index++;
	}
	s[0] = (index - 1) + 48;

	return 0;
}

int bcd_decode(char *s)
{
	int retval = 0;	

	int i;
	for (i = 1; i <= (s[0] - 48); i++)
	{
		retval += ((s[i] - 48) * pow(10, i - 1));
	}

	return retval;
}

int bcd_gt(char *s, char *t)
{
	if (s[0] > t[0])
	{
		return 1;
	}
	else if (s[0] < t[0])
	{
		return 0;
	}
	else
	{
		int i;
		for (i = (s[0] - 48); i > 0; i--)
		{
			if (s[i] > t[i])
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		return 0;
	}
}

int bcd_eq(char *s, char *t)
{
	int i;
	for (i = 0; i <= (s[0] - 48); i++)
	{
		if (s[i] != t[i])
		{
			return 0;
		}
	}

	return 1;
}

int bcd_add(char *s, char *t, int n, char *u)
{
	// copy array
	char sc[strlen(s)], tc[strlen(t)];
    int is;
    for (is = 0; is < strlen(sc); is++)
    {
        sc[is] = s[is];
    }
    int it;
    for (it = 0; it < strlen(tc); it++)
    {
        tc[it] = t[it];
    }
	
	// pad zeros
	int maxd;
	if (sc[0] > tc[0])
	{
	    maxd = sc[0] - 48;
            
	}
	else if (tc[0] > sc[0])
	{
		maxd = tc[0] - 48;
	}
	else
	{
	    maxd = sc[0] - 48;
	}	
	int i;
    for (i = 1; i <= (maxd - (sc[0] - 48) + 1); i++)
    {
        sc[(sc[0] - 48) + i] = '0';
    }
    
    int j;
    for (j = 1; j <= (maxd - (tc[0] - 48) + 1); j++)
    {
        tc[(tc[0] - 48) + j] = '0';
    }
    
    // perform addition
    int k;
    for (k = 0; k <= maxd + 1; k++)
    {
        u[k] = '0';
    }
    
    int l;
    for (l = 1; l <= maxd + 1; l++)
    {
        if (((sc[l] - 48) + (tc[l] - 48)) > 10)
        {
            u[l] = (u[l] - 48) + (sc[l] - 48) + (tc[l] - 48) - 10 + 48;
            u[l + 1] = '1';
        }
        else
        {
            u[l] = (u[l] - 48) + (sc[l] - 48) + (tc[l] - 48) + 48;
        }
    }
	
	if (u[maxd + 1] == '0')
	{
	    u[0] = maxd + 48;
	}
	else
	{
	    u[0] = (maxd + 1) + 48;
	}
	
	return 0;
}

int bcd_sub(char *s, char *t, int n, char *u)
{
    
}

int bcd_mul(char *s, char *t, int n, char *u)
{
    int mult;
    mult = 0;	

    int i;
	for (i = 0; i < n; i++)
	{
		u[i] = '0';
	}
	u[0] = '1';
	
	int j;
	for (j = 1; j <= (s[0] - 48); j++)
	{
		mult += ((s[j] - 48) * pow(10, j - 1));
	}
	
	int k;
	for (k = 0; k < mult; k++)
	{
	    bcd_add(u, t, n, u);
	}
	
	return 0;
}

int bcd_div(char *s, char *t, int n, char *u, int m, char *v) { return -1; }

