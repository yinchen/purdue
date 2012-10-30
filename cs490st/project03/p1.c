#include <stdio.h>


int main() {

    int e  = 0;
    int a = 0, b = 0, c = 0, d = 0;
    
    klee_make_symbolic(&a, sizeof(a), "a");
    klee_make_symbolic(&b, sizeof(b), "b");
    klee_make_symbolic(&c, sizeof(c), "c");
    klee_make_symbolic(&d, sizeof(d), "d");

    if (a > 10) {
        e += 0;

        if (3*b + 27 == 300) {
            e += 0;
        }
        else if (a + b > 24) {
            e += 1;
        }
        else if (b < 500) {
            e += 2;
        }
        else if (b < 300) {
            e += 3;
        }
    }
    else if (d > 0) {
        e += 4;

        if (d < a) {
            e += 0;
        }
        else if (c + 10 < d) {
            e += 1;
        }
        else  {
            e += 2;
        }
    }
    else {
        e += 7;

        if (a + 3*b < 2*c + d) {
            e += 0;
        }
        else {
            e += 1;
        }
    }

    printf ("%d\n", e);

    return 0;
}
