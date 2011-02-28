#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int main()
{
	int n;
	scanf("%d", &n);
	
	float* x;
	x = (float*) malloc(n * sizeof(int));
	float* y;
    y = (float*) malloc(n * sizeof(int));
    
	int i;
    for (i = 0; i < n; i++)
    {
        if (scanf("%f %f", &x[i], &y[i]) != 2)
        {
            printf("Pair x,y[%d] missing\n", i);
            exit(1);
        }
    }
    
    float sum;
    sum = 0.0;
    
    for (i = 1; i < n; i++)
    {
        sum = sum + ((x[i] - x[i-1]) * (y[i] + y[i-1]));
    }
    sum = 0.5 * sum;
    
    printf("The value of the integral is %f\n", sum);
}
