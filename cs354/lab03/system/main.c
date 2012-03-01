/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*																		*/
/* main - main program for testing Xinu									*/
/*																		*/
/************************************************************************/

void producer(pipid32 pip)
{
	// DEBUG
	kprintf("BRK3\r\n");

	int i;
	for (i = 0; i < 10; i++)
	{
		pipwrite(pip, "matt is cool", 12);
	}

	// DEBUG
	kprintf("BRK4\r\n");
}

void consumer(pipid32 pip)
{
	// DEBUG
	kprintf("BRK5\r\n");

	int i;
	for (i = 0; i < 10; i++)
	{
		char *buf;
		pipwrite(pip, buf, 12);

		kprintf(buf);
    	kprintf("\r\n");
	}

	// DEBUG
	kprintf("BRK6\r\n");
}

int main(int argc, char **argv)
{
	// DEBUG
	kprintf("BRK1\r\n");

	pipid32 pip = pipcreate();

	// DEBUG
	kprintf("BRK2\r\n");

    pid32 prpid = create(producer, 500, 20, "producer", 1, pip);
    pid32 copid = create(consumer, 500, 20, "consumer", 1, pip);

    // DEBUG
	kprintf("BRK7\r\n");

    pipconnect(pip, prpid, copid);

    // DEBUG
	kprintf("BRK8\r\n");

    resume(prpid);
	resume(copid);

	// DEBUG
	kprintf("BRK9\r\n");

	pipdisconnect(pip);
	pipdelete(pip);

	// DEBUG
	kprintf("BRK10\r\n");
    
    return OK;
}
