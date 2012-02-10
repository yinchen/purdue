/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*                                                                      */
/* main - main program for testing Xinu                                 */
/*                                                                      */
/************************************************************************/

void printc(char c)
{
	int i;
	while (1)
	{
		kprintf("%c", c);
		for (i = 0; i < 10000; i++);
	}
}

int main(int argc, char **argv)
{
    resume(create(printc, 500, 30, "sleeper 1", 1, 'A'));
    resume(create(printc, 500, 30, "sleeper 2", 1, 'B'));

    printc('D');
    
    return OK;
}
