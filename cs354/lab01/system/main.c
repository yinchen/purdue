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
    kprintf("Hello World!\r\n");
    kprintf("\r\n");

    uint32 i;

    resume(create((void*)sleep(10), 200, 20, "sleeper 1", 0));
    resume(create((void*)sleep(10), 200, 20, "sleeper 2", 0));
    
    for (i = 0; i < NPROC; i++)
    {
        print_proc_info(i);
    }

    return OK;
}
