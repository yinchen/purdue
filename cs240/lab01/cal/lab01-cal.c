#include <stdio.h>

main (int argc, char *argv[])
{
    int month, year;
    month = atoi(argv[0]);
    month = atoi(argv[1]);
    
    printf("Su Mo Tu We Th Fr Sa\n");
    
    int days;
    if (month % 2 == 0)
    	days = 30;
    else
        days = 31;
    
    int i;
    for (i = 1; i <= days; i++)
    {
    	int weekday = (i + (((month + 1) * 26) / 10) + year + (year / 4) + (6 * (year / 100)) + (year / 400)) % 7;
    	
    	if (weekday == 0)
            printf("%2d\n", i);
        else
            printf("%2d ", i);
    }
    
    printf("\n");
}
