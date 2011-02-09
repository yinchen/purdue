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
	if (s[0] > t[0])
	{
		u[0] = s[0];
	}
	else
	{
		u[0] = t[0];
	}
}

int bcd_sub(char *s, char *t, int n, char *u) { return -1; }
int bcd_mul(char *s, char *t, int n, char *u) { return -1; }
int bcd_div(char *s, char *t, int n, char *u, int m, char *v) { return -1; }

int main()
{
	int i, j, k, a, b;
	char s[128], t[128], u[128], v[128];

	bcd_encode(127, 128, s);
	bcd_encode(127, 128, t);
	printf("bcd_encode(s): %s\n", s);
	printf("bcd_encode(t): %s\n", t);

	printf("\n");

	printf("bcd_gt: %d\n", bcd_gt(t, s));

	return 0;
}
