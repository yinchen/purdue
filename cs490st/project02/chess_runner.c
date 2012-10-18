#include <stdio.h>
#include <stdlib.h>

// enter the sample number you would like to explore (i.e. 1 for sample1, 2 for sample2, etc.)
#define SAMPLE_NUMBER 1

int main()
{
    puts("Exploring...");

    FILE *data0 = fopen("curr.txt", "w");
    fputs("-1\n", data0);
    fclose(data0);

    if (SAMPLE_NUMBER == 1)
        system("./run.sh ./sample1");
    else if (SAMPLE_NUMBER == 2)
        system("./run.sh ./sample2");
    else
        exit(-1);

    int max = 0;

    FILE *data1 = fopen("max.txt", "r");
    char line[1024];
    fgets(line, 1024, data1);
    fclose(data1);

    max = atoi(line);

    FILE *data2 = fopen("curr.txt", "w");
    fputs("1\n", data2);
    fclose(data2);

    int i = 1;
    while (i <= max)
    {
        fprintf (stderr, "Executing step %d of %d\n", i, max);
        
        if (SAMPLE_NUMBER == 1)
            system("./run.sh ./sample1");
        else if (SAMPLE_NUMBER == 2)
            system("./run.sh ./sample2");
        else
            exit(-1);

        FILE *data3 = fopen("curr.txt", "w");
        fprintf(data3, "%d\n", i + 1);
        fclose(data3);

        i++;
    }

    return 0;
}
