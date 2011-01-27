/* 
 * convert.c
 * Lab 2
 *
 * Your next task for this lab is to write a program that when 
 * provided with a month (first argument) and an year (second 
 * argument), outputs the calender for that month as shown in 
 * the example above. Make sure that you print the correct 
 * number of days (28, 29, 30 or 31) for each month.
 * 
 * @author Matt McCormick (mbmccorm@purdue.edu)
 * @section R1130
 * @date 01/27/2010
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int convertToBase10(char num[], int base);
char convertFromBase10(int num, int base);

main (int argc, char *argv[])
{
    int num, frombase, tobase;
    num = atoi(argv[1]);
    frombase = atoi(argv[2]);
    tobase = atoi(argv[3]);
    
    printf("%d\n", convertFromBase10(num, tobase));
}

int convertToBase10(char num[], int base)
{
    int retval;
    retval = 0;
    
    int i;
    for (i = 0; i < strlen(num); i++)
    {
        int n;
        n = strlen(num) - i - 1;
        
        retval += ((num[i] - 48) * pow(base, n));
    }
    
    return retval;
}

char convertFromBase10(int num, int base)
{
    int result;
    result = num / base;
    
    do
    {
        printf("%d\n", num % result);
        result = result / base;
        
    } while (result != 0);
}
