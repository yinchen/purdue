#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Exploring...");

    system("run.sh sample1");

    int max = 0;

    FILE *data = fopen("max.txt", "r");
    char line[1024];
    fgets(line, 1024, data);

    max = atoi(line);

    int i = 1;
    while (i <= max)
    {
        fprintf (stderr, "Executing step %d of %d\n", i, max);
        system("./run.sh ./sample1");

        i++;
    }

    return 0;
}
