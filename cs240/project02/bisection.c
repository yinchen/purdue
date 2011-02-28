/* A program that finds a root using the bisection method */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOLERANCE 0.01

double f(const char* funname, double x);
void printFunction();

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        printf("Usage: bisection <poly|sin|cos|xsin|imaginary> <left bound> <right bound>\n");
        exit(1);
    }
    
    char *func = argv[1];
    double a = (double)atoi(argv[2]);
    double b = (double)atoi(argv[3]);
    
    printFunction(func);
    
    if (b <= a)
    {
        printf("Boundary ( %f, %f), ( %f, %f) is invalid\n", a, f(func, a), b, f(func, b));
        exit(0);
    }
    
    if ((f(func, a) > 0.0 && f(func, b) > 0.0) ||
        (f(func, a) < 0.0 && f(func, b) < 0.0))
    {
        printf("Boundary ( %f, %f), ( %f, %f) is invalid\n", a, f(func, a), b, f(func, b));
        exit(0);
    }
    
    if (f(func, a) == 0.0 ||
        f(func, b) == 0.0)
    {
        printf("One of the boundary points ( %f, %f), ( %f, %f) is already a solution\n", a, f(func, a), b, f(func, b));
        exit(0);
    }
    
    double m;
    
    int i = 0;   
    while ((b - a) > TOLERANCE)
    {
        m = ((b - a) / 2) + a;
        
        printf("At iteration %d, the three points are ( %f, %f), ( %f, %f), ( %f, %f)\n", i, a, f(func, a), m, f(func, m), b, f(func, b));
        
        if ((f(func, a) > 0.0 && f(func, m) > 0.0) ||
            (f(func, a) < 0.0 && f(func, m) < 0.0))
        {
            a = m;
        }
        else if (f(func, m) == 0.0)
        {
            break;
        }
        else
        {
            b = m;
        }
        
        i++;
    }
    
    if (f(func, m) == 0.0)
    {
        printf("( %f, %f) is an exact solution\n", m, f(func, m));
        exit(0);
    }
    else
    {
        printf("Solution is in the range ( %f, %f)\n", m, b);
        exit(0);
    }
}

/* Prints the function in readable form */
void printFunction(const char * funname)
{
    char * func;

	if(strcmp(funname, "poly") == 0)
	  func = "y = x^2 - 4 = 0";
  	else if(strcmp(funname, "cos") == 0)
  		func = "y = cos(x) - x^3 = 0";
	else if(strcmp(funname, "sin") == 0)
	  func = "y = sin(x)-.5 = 0";
	else if(strcmp(funname, "xsin") == 0)
	  func = "y = x*sin(x)-10 = 0";
	else if(strcmp(funname, "imaginary") == 0)
	  func = "y = x^2+1 = 0";
	else
	{
	  printf("Error: %s is not a valid function name\n", funname);
		exit(1);
	}

    printf("Function: %s\n", func);
}

/* Evaluates f(x) */
double f(const char* funname, double x)
{
	if(strcmp(funname, "poly") == 0)
		return (x*x - 4);
	else if(strcmp(funname, "cos") == 0)
		return (cos(x) - x*x*x);
	else if(strcmp(funname, "sin") == 0)
	  return (sin(x)-.5);
	else if(strcmp(funname, "xsin") == 0)
	  return (x*sin(x)-10);
	else if(strcmp(funname, "imaginary") == 0)
	  return (x*x+1);
	else
	{
	  printf("Error: %s is not a valid function name\n", funname);
		exit(1);
	}
}
