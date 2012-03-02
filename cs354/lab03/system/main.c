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
	while(1)
	{
	    int i;
	    for (i = 0; i < 10; i++)
	    {
	        pipwrite(pip, "matt is cool", 13);
	    }
	    
	    suspend(getpid());
    }
}

void consumer(pipid32 pip)
{
	while(1)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
		    int count = 0;
			char buf[13];
			
			count = pipread(pip, buf, 13);

			kprintf("%s\r\n", buf, count);
		}

		suspend(getpid());
	}
}

int main(int argc, char **argv)
{
	pipid32 pip = pipcreate();

	pid32 prpid = create(producer, 500, 20, "producer", 1, pip);
    pid32 copid = create(consumer, 500, 20, "consumer", 1, pip);

    pipconnect(pip, prpid, copid);

    resume(prpid);
	resume(copid);

	while (1)
	{
		char c = getchar();

		if (c == 'q')
		{
			break;
		}
		else if (c == '\n')
		{
		    resume(prpid);
			resume(copid);
		}
	}

	pipdisconnect(pip);
	pipdelete(pip);

    kprintf("\r\n");
    kprintf("Goodbye.\r\n");

	return OK;
}
