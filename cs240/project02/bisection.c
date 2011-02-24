/* A program that finds a root using the bisection method */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOLERANCE 0.01

double f(const char* funname, double x);
void printFunction();

int main(int argc, char** argv)
{
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
