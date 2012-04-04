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
		kprintf("SND: 4\r\n");

		sendb(prB, 4);	

		i++;
	}

	while(1) {} // noop
}

void processB1(void)
{
	int i = 0;
	while(i < 5)
	{
		kprintf("RCV: %d\r\n", receiveb());

	    i++;
    }

    while(1) {} // noop
}

void processB2(void)
{
	while(1) {} // noop
}

int main(int argc, char **argv)
{
	pid32 prB1 = create(processB1, 500, 20, "processB1", 0);
	resume(prB1);

	pid32 prB2 = create(processB2, 500, 20, "processB2", 0);
	resume(prB2);

	pid32 prA = create(processA, 500, 20, "processA", 1, prB1);
	resume(prA);

	return OK;
}
