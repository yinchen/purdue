#include <stdio.h>

main (int argc, char *argv[])
{
    int month, year;
    month = atoi(argv[1]);
    year = atoi(argv[2]);

    if (month == 1 || month == 2)
        year = year + 1;
    
    int days;
    if (month <= 7)
        if (month % 2 == 0)
        	days = 30;
        else
            days = 31;
    else
        if (month % 2 == 0)
            days = 31;
        else
            days = 30;
    if (month == 2)
        if ((year - 1) % 4 == 0)
            days = 29;
        else
            days = 28;

    printf("Su Mo Tu We Th Fr Sa\n");
    
    int i;
    int isFirst = 1;
    for (i = 1; i <= days; i++)
    {
        int weekday = (i + (((month + 1) * 26) / 10) + year + (year / 4) + (6 * (year / 100)) + (year / 400)) % 7;
        
        if (month == 2)
            if (weekday == 6)
                weekday = 0;
            else
                weekday = weekday + 1;

    	if (isFirst == 1)
        {
            if (weekday == 0)
            {
                printf("                  ");
            }
            else
            {
                int j;
                for (j = 0; j < (weekday - 1); j++)
                    printf("   ");
                isFirst = 0;
            }
        }
        
        if (weekday == 0)
            printf("%2d\n", i);
        else
            printf("%2d ", i);
    }
    
    printf("\n");
}
