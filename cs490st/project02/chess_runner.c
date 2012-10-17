#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Exploring...");

    FILE *data0 = fopen("curr.txt", "w");
    fputs("-1\n", data0);
    fclose(data0);

    system("./run.sh ./sample1");

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
        system("./run.sh ./sample1");

        i++;
    }

    return 0;
}
