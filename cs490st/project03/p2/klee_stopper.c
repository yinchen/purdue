#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    double a = 0.0, b = 0.0;
    // double a = 0.0, b = -0.25;
    
    klee_make_symbolic(&a, sizeof(a), "a");
    klee_make_symbolic(&b, sizeof(b), "b");

    if ((8 * a * a) + (4 * b) + 1 == 0)
    {
        printf("KLEE should not be able to get here\n");
        abort();
    }
    else
    {
    	printf("KLEE is not very smart\n");
    }

    return 0;
}
