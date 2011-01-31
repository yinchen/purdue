/* 
 * convert.c
 * Lab 2
 *
 * In this lab you will create a program to convert a number 
 * from one base system to another base system.
 * 
 * @author Matt McCormick (mbmccorm@purdue.edu)
 * @section R1130
 * @date 01/27/2010
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

void validateBase(char num[], int frombase, int tobase);
int convertToBase10(char num[], int base);
void convertFromBase10(int num, int base);

main (int argc, char *argv[])
{
    if (argv[1] == NULL ||
        argv[2] == NULL ||
        argv[3] == NULL)
    {
        printf("Usage convert <number> <from_base> <to_base>\n");
        exit(0);
    }
    
    int frombase, tobase;
    frombase = atoi(argv[2]);
    tobase = atoi(argv[3]);
    
    validateBase(argv[1], frombase, tobase);
    
    int tmp;
    tmp = convertToBase10(argv[1], frombase);
    
    convertFromBase10(tmp, tobase);
}

void validateBase(char num[], int frombase, int tobase)
{
    if (frombase < 2 ||
        frombase > 35)
    {
        printf("The bases should lie between 2 and 35\n");
        exit(0);
    }
    
    if (tobase < 2 ||
        tobase > 35)
    {
        printf("The bases should lie between 2 and 35\n");
        exit(0);
    }
    
    if (strlen(num) > 32)
    {
        printf("The entered number is longer than 32 digits, please enter a smaller number\n");
        exit(0);
    }
    
    if (frombase > 10)
    {
        char base_digits[36] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    
        int i;
        i = 0;
        do
        {
            int j;
            int invalid = 1;
            for (j = 0; j < frombase; j++)
            {
                if (toupper(num[i]) == base_digits[j])
                {
                    invalid = 0;
                }
            }
            
            if (invalid == 1)
            {
                printf("Quitting for %c with base %d\n", num[i], frombase);
                printf("The entered number is invalid for the given base\n");
                exit(0);
            }
            
            i++;
        } while (num[i] != '\0');
    }
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
        
        if (toupper(num[i]) > 57)
            retval += ((toupper(num[i]) - 55) * pow(base, n));
        else
            retval += ((toupper(num[i]) - 48) * pow(base, n));
    }
    
    return retval;
}

void convertFromBase10(int num, int base)
{
    int result[64];
    char base_digits[36] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    
    int i, j;
    i = 0;
    
    while (num != 0)
    {
        result[i] = num % base;
        num = num / base;
        i++;
    }
    
    for(j = i - 1; j>=0; j--)
    {
        printf("%c", tolower(base_digits[result[j]]));
    }
    
    printf("\n");
}
