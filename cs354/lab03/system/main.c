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
	int i;
	for (i = 0; i < 10; i++)
	{
		pipwrite(pip, "matt is cool", 12);
	}
}

void consumer(pipid32 pip)
{
	while(1)
	{
		int i;
		for (i = 0; i < 10; i++)
		{
			char buf[12];
			pipread(pip, buf, 12);

			kprintf("%s\r\n", buf);
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
			resume(copid);
		}
	}

	// pipdisconnect(pip);
	// pipdelete(pip);

	return OK;
}
