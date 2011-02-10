#include <stdio.h>
#include <string.h>
#include <math.h>

void stealNextDigit(char *sc, int n);

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
	char sc[n], tc[n];
    int is;
    for (is = 0; is < n; is++)
    {
        sc[is] = s[is];
    }
    int it;
    for (it = 0; it < n; it++)
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
    
    // zero array
    int k;
    for (k = 0; k <= maxd + 1; k++)
    {
        u[k] = '0';
    }
    u[0] = '1';
    
    // perform addition
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
	
	if ((u[maxd + 1] - 48) == 0)
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
    // copy array
	char sc[n], tc[n];
    int is;
    for (is = 0; is < n; is++)
    {
        sc[is] = s[is];
    }
    int it;
    for (it = 0; it < n; it++)
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
    for (i = 1; i <= (maxd - (sc[0] - 48)); i++)
    {
        sc[(sc[0] - 48) + i] = '0';
    }    
    int j;
    for (j = 1; j <= (maxd - (tc[0] - 48)); j++)
    {
        tc[(tc[0] - 48) + j] = '0';
    }
    
    // zero array
    int k;
    for (k = 0; k <= maxd; k++)
    {
        u[k] = '0';
    }
    u[0] = '1';
    
    // prepare digits
    int l;
    for (l = 1; l < maxd; l++)
    {
        if (sc[l] < tc[l])
        {
            stealNextDigit(sc, l);
        }
    }
	
	// perform subtraction
	int m;
	for (m = 1; m <= maxd; m++)
	{
	    u[m] = (sc[m] - 48) - (tc[m] - 48) + 48;
	}
	
	// correct digit count
	int z;
	for (z = maxd; z >= 1; z--)
	{
	    if ((u[z] - 48) > 0)
	    {
	        break;
	    }
	}
	u[0] = z + 48;
	
	return 0;
}

void stealNextDigit(char *sc, int n)
{
    if ((sc[n + 1] - 48) == 0)
    {
        stealNextDigit(sc, n + 1);
    }
    
    sc[n + 1] = sc[n + 1] - 1;
    sc[n] = sc[n] + 10;
    
    return;
}

int bcd_mul(char *s, char *t, int n, char *u)
{
    // zero array
    int i;
	for (i = 0; i < n; i++)
	{
		u[i] = '0';
	}
	u[0] = '1';
	
	// calculate multiplier
	int mult;
    mult = 0;	
    int j;
	for (j = 1; j <= (t[0] - 48); j++)
	{
		mult += ((t[j] - 48) * pow(10, j - 1));
	}
	
    // perform addition
	int k;
	for (k = 0; k < mult; k++)
	{
	    bcd_add(u, s, n, u);
	}
	
	return 0;
}

int bcd_div(char *s, char *t, int n, char *u, int m, char *v)
{
    // initialize array
    int i;
	for (i = 0; i < n; i++)
	{
		u[i] = s[i];
	}
	
	// perform subtraction
    int j;
    j = 0;
	while (bcd_gt(u, t) == 1 ||
	       bcd_eq(u, t) == 1)
	{
	    bcd_sub(u, t, n, u);	    
	    j++;
	}
	bcd_encode(j, n, u);
	
	// calculate remainder
	char tmp[n];
	bcd_mul(t, u, n, tmp);
	bcd_sub(s, tmp, n, v);
	
	return 0;
}

