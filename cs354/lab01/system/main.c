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
    pid32 proc1, proc2;

    // print currently running processes
    for (i = 0; i < NPROC; i++)
    {
        print_proc_info(i);
    }

    proc1 = create((void*)sleep(10), 200, 20, "sleeper 1", 0);
    proc2 = create((void*)sleep(10), 200, 20, "sleeper 2", 0);
    
    // print currently running processes
    for (i = 0; i < NPROC; i++)
    {
        print_proc_info(i);
    }

    resume(proc1);
    resume(proc2);

    // print currently running processes
    for (i = 0; i < NPROC; i++)
    {
        print_proc_info(i);
    }

    return OK;
}
