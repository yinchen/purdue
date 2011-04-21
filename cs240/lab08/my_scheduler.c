#include <stdio.h>
#include <signal.h>
#include "my_scheduler.h"

void scheduler(void (*func[])(), int len);
void handle_signal(int signo);
void initHandlers();

jmp_buf env;

void scheduler(void (*func[])(), int len)
{
	int result;
	result = setjmp(env);
	
	if (result == 0)
	{
		while (1)
		{
			initHandlers();
		
			int i;
			for (i = 0; i < len; i++)
			{
				func[i]();
				setjmp(env);
			}
		}
	}
	else
	{
		printf("ERROR: setjmp() failed!\n");
		exit(1);
	}
}

void handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		printf("SIG: Interrupt received. Exiting\n");
		exit(0);
	}
	else if (signo == SIGFPE)
	{
		printf("SIG: Floating point exception encountered\n");
		longjmp(env, 2);
	}
	else if (signo == SIGSEGV)
	{
		printf("SIG: Segmentation fault encountered\n");
		longjmp(env, 2);
	}
	else if (signo == SIGALRM)
	{
		printf("SIG: Alarm went off!\n");
		longjmp(env, 2);
	}
}

void initHandlers()
{
	if (signal(SIGINT, handle_signal) == SIG_ERR)
	{
		printf("ERROR: Could not create signal handler!\n");
		exit(1);
	}
	
	if (signal(SIGFPE, handle_signal) == SIG_ERR)
	{
		printf("ERROR: Could not create signal handler!\n");
		exit(1);
	}
	
	if (signal(SIGSEGV, handle_signal) == SIG_ERR)
	{
		printf("ERROR: Could not create signal handler!\n");
		exit(1);
	}
	
	if (signal(SIGALRM, handle_signal) == SIG_ERR)
	{
		printf("ERROR: Could not create signal handler!\n");
		exit(1);
	}
}
