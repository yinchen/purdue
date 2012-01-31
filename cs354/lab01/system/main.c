/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*                                                                      */
/* main - main program for testing Xinu                                 */
/*                                                                      */
/************************************************************************/

void noop(void)
{
	sleep(5000);
}

int main(int argc, char **argv)
{
    kprintf("Hello World!\r\n");
    kprintf("\r\n");

    pid32 i;
    
    resume(create(noop, 200, 20, "sleeper 1", 0));
    resume(create(noop, 200, 20, "sleeper 2", 0));
    
    // print currently running processes
    for (i = 0; i < NPROC - 1; i++)
    {
        print_proc_info(i);
    }

    return OK;
}
