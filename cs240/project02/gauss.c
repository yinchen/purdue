/* A program that solves linear systems using Gauss-Jordan*/

#include <stdio.h>
#include <stdlib.h>

#define TOLERANCE 1E-6
#define MAXROWS 100
#define MAXCOLS 101

void printMatrix(int rows, int columns, double matrix[][MAXCOLS]);

int main()
{
	double matrix[MAXROWS][MAXCOLS];
}

void printMatrix(int rows, int columns, double matrix[][MAXCOLS])
{
	int r, c;

	printf("MATRIX:\n");
	for(r=0; r < rows; r++)
	{
		for(c=0; c < columns; c++)
			printf("%f ", matrix[r][c]);
		printf("\n");
	}
	printf("\n");
}
