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
	kprintf("A : Sending 10 messages...\r\n");

	int32 i = 0;
	while (i < 10)
	{
		kprintf("A : Sending message.\r\n");

		sendb(prB, 4);

		kprintf("A : Message sent.\r\n");	

		i++;
	}
}

void processB1(void)
{
	kprintf("B1: Receiving 5 messages...\r\n");

	int i = 0;
	while(i < 5)
	{
		kprintf("B1: Receiving message.\r\n");

	    kprintf("B1: %d\r\n", receiveb());

	    kprintf("B1: Message received.\r\n");

	    i++;
    }
}

void processB2(void)
{
	while(1)
	{
		// noop
	}
}

int main(int argc, char **argv)
{
	kprintf("Creating new processes.\r\n");

	pid32 prB1 = create(processB1, 500, 20, "processB1", 0);
	resume(prB1);

	pid32 prB2 = create(processB2, 500, 20, "processB2", 0);
	resume(prB2);

	pid32 prA = create(processA, 500, 20, "processA", 1, prB2);
	resume(prA);

	kprintf("Exiting.\r\n");

	return OK;
}
