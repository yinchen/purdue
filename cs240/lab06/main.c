#include <stdio.h>
#include <stdlib.h>
#include "separate.h"

int *mallocInt(int val);
double *mallocDouble(double val);

int main()
{
	void *array[10] = {&"a", &"b", &"c", &"1", &"2", &"3", &"x", &"y", &"z", &"0"};
	
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("array[%d] = %c\n", i, *(char *)array[i]);
	}
	
	/*
	 * Expect: a, b, c, 1, 2, 3, x, y, z, 0
	 */
	
	separate(array, 10, &isalpha_separator);
	printf("separate(array, 10, &isalpha_separator);\n");
	
	
	for(i = 0; i < 10; i++)
	{
		printf("array[%d] = %c\n", i, *(char *)array[i]);
	}
	
	/*
	 * Expect: 1, 2, 3, 0, a, b, c, x, y, z
	 */
	
	void *array2[10] = {mallocInt(1), mallocInt(-10), mallocInt(-8), mallocInt(3), mallocInt(5),
						mallocInt(-6), mallocInt(7), mallocInt(-4), mallocInt(9), mallocInt(-2)};
	for(i = 0; i < 10; i++)
	{
		printf("array2[%d] = %d\n", i, *(int *)array2[i]);
	}
	
	/*
	 * Expect: 1, -10, -8, 3, 5, -6, 7, -4, -9, -2
	 */
	
	separate(array2, 10, &positiveInt_separator);
	printf("separate(array2, 10, &positiveInt_separator;\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("array2[%d] = %d\n", i, *(int *)array2[i]);
	}
	
	/*
	 * Expect: -10, -8, -6, -4, -2, 1, 3, 5, 7, 9
	 */
	 
	 void *array3[10] = {mallocDouble(2.6), mallocDouble(1.0), mallocDouble(3.0), mallocDouble(5.0), mallocDouble(4.001),
	 					 mallocDouble(6.000013), mallocDouble(7), mallocDouble(8.02), mallocDouble(9.000), mallocDouble(10.111)};

	for(i = 0; i < 10; i++)
	{
		printf("array3[%d] = %lf\n", i, *(double *)array3[i]);
	}
	
	/*
	 * Expect: 2.6, 1, 3, 5, 4.001, 6.000013, 7, 8.02, 9, 10.111
	 */
	
	separate(array3, 10, &iswholeDouble_separator);
	printf("separate(array3, 10, &iswholeDouble_separator);\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("array3[%d] = %lf\n", i, *(double *)array3[i]);
	}
	
	/*
	 * Expect: 2.6, 4.001, 6.000013, 8.02, 10.111, 1, 3, 5, 7, 9
	 */
}

int *mallocInt(int val) 
{
	int *temp = (int *)malloc(sizeof(int));	
	*temp = val;
	return temp;
}

double *mallocDouble(double val)
{
	double *temp = (double *)malloc(sizeof(double));
	*temp = val;
	return temp;
}
