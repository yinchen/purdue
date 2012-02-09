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
	sleep(10);
}

int main(int argc, char **argv)
{
    resume(create(noop, 500, 30, "sleeper 1", 0));
    resume(create(noop, 500, 30, "sleeper 2", 0));
    
    return OK;
}