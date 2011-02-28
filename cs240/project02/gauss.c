#include <stdio.h>
#include <stdlib.h>

#define TOLERANCE 1E-6
#define MAXROWS 100
#define MAXCOLS 101

void printMatrix(int rows, int columns, double matrix[][MAXCOLS]); // double matrix[][MAXCOLS]);

int main()
{
	double matrix[MAXROWS][MAXCOLS]; // double matrix[MAXROWS][MAXCOLS];
	
	// read size of matrix
	int n;
	scanf("%d", &n);
	
	// read matrix values
    int i;
    for (i = 0; i < n; i++) // for each row
    {
        int j;
        for (j = 0; j < n + 1; j++) // for each column
        {
            if (scanf("%lf", &matrix[i][j]) != 1)
            {
                printf("Element a[%d][%d] is missing\n", i, j);
                exit(1);
            }
        }
    }
    
    // print matrix
    printf("initial matrix\n");
    printMatrix(n, n + 1, matrix);
    
    int k;
    for (k = 0; k < n; k++) // for each row(i)
    {
        // check for TOLERANCE threshold
        if (matrix[k][k] < TOLERANCE && matrix[k][k] > (TOLERANCE * -1))
        {
            printf("Error: Current pivot (%d, %d) is practically zero\n", k, k);
            exit(1);
        }
        
        // print operation
        printf("row %d /= %f\n", k, matrix[k][k]);
        
        double k_div;
        k_div = matrix[k][k];
                    
        int k2;
        for (k2 = 0; k2 < n + 1; k2++) // for each column in row(i)
        {
            matrix[k][k2] = matrix[k][k2] / k_div;
            
            if (matrix[k][k2] == -0.0) { matrix[k][k2] = 0.0; }
        }
        
        // print matrix
        printMatrix(n, n + 1, matrix);
        
        int l;
        for (l = 0; l < n; l++) // for each row(k)
        {
            if (l != k)
            {
                // print operation
                printf("row %d -= %f row %d\n", l, matrix[l][k], k);
                
                double l_mul;
                l_mul = matrix[l][k];
                
                int l2;
                for (l2 = 0; l2 < n + 1; l2++) // for each column in row(k)
                {
                    matrix[l][l2] = matrix[l][l2] - (l_mul * matrix[k][l2]);
                }
                            
                // print matrix
                printMatrix(n, n + 1, matrix);
            }
        }
    }
    
    // print solution
    printf("SOLUTION:\n");
    
    // printf("%f", matrix[0][n]);
    for (i = 0; i < n; i++) // for each row // for (i = 1; i < n; i++) // for each row
    {
        printf("%f ", matrix[i][n]); // printf(" %f", matrix[i][n]);
    }
    printf("\n");
}

void printMatrix(int rows, int columns, double matrix[][MAXCOLS]) // double matrix[][MAXCOLS])
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
