/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*																		*/
/* main - main program for testing Xinu									*/
/*																		*/
/************************************************************************/

void processA(pid32 prB)
{
	int32 i = 0;
	while (i < 10)
	{
		kprintf("Sending message.\r\n");

		sendb(prB, 4);

		kprintf("Message sent.\r\n");	

		i++;
	}
}

void processB1()
{
	while(1)
	{
		kprintf("Receiving message.\r\n");

	    kprintf("RCV: %d\r\n", receiveb());

	    kprintf("Message received.\r\n");
    }
}

void processB2()
{
	kprintf("Ignoring messages.\r\n");
}

int main(int argc, char **argv)
{
	kprintf("Creating new processes.\r\n");

	pid32 prB1 = create(processB1, 500, 20, "processB", 0);
	resume(prB1);

	pid32 prB2 = create(processB2, 500, 20, "processB2", 0);
	resume(prB2);

	pid32 prA = create(processC, 500, 20, "processA", 1, prB2);
	resume(prA);

	kprintf("Exiting.\r\n");

	return OK;
}
