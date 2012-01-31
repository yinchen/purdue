/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*                                                                      */
/* main - main program for testing Xinu                                 */
/*                                                                      */
/************************************************************************/

int main(int argc, char **argv)
{
    kprintf("Hello World!\n\n");

    uint32 i;

    for (i = 0; i < NPROC; i++)
    {
        print_proc_info(i);
    }
    
    return OK;
}
