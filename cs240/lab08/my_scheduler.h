#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>

/* Schedules task 
 * Input arguments:
 * func: array of function pointers that indicate the tasks to be executed
 * len: number of tasks to be executed */
void scheduler(void (*func[])(), int len);

/* Signal Handlers: define the behavior of signal handling */
void handle_signal(int signo);

/* Init Handlers: assign the handlers for various signals.
 *  */
void initHandlers();
