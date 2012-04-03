/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*																		*/
/* main - main program for testing Xinu									*/
/*																		*/
/************************************************************************/

void processB(pid32 prA)
{
	while(1)
	{
	    kprintf("%d", receiveb());
    }
}

int main(int argc, char **argv)
{
	pid32 prB = create(processB, 500, 20, "processB", 1, currpid);
	resume(prB);

	while (1)
	{
		sendb(prB, 4);
	}

	return OK;
}
