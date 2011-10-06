#include <stdio.h>
#include <string.h>

void mdump(int start, int end)
{

}

int main()
{
    int n;
    n = sizeof(void *);

    int bit;
    if (n == 4)
    {
        bit = 32; 
    }
    else
    {
        bit = 64;
    }

    char *endian;
    int num = 1;
    if (*(char *)&num == 1)
    {
        endian = "Little";
    }
    else
    {
        endian = "Big";
    }

    printf("Memory Dump (%d-bit %s Endian Machine)\n", bit, endian); 
    printf("Address Words In Hexadecimal ASCII characters\n");
    printf("--------- -------- -------- -------- -------- ----------------\n");
}

