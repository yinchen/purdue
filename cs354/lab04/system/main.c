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
		kprintf("Receiving message.\r\n");

	    kprintf("RCV: %d\r\n", receiveb());

	    kprintf("Message received.\r\n");
    }
}

void processC(pid32 prA)
{
	kprintf("Ignoring messages.\r\n");
}

int main(int argc, char **argv)
{
	kprintf("Creating new process.\r\n");

	pid32 prB = create(processB, 500, 20, "processB", 1, currpid);
	resume(prB);

	pid32 prB = create(processB, 500, 20, "processC", 1, currpid);
	resume(prB);

	while (1)
	{
		kprintf("Sending message.\r\n");

		sendb(prC, 4);

		kprintf("Message sent.\r\n");	
	}

	kprintf("Exiting.\r\n");

	return OK;
}
