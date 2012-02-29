/* pipread.c - pipread */

#include <xinu.h>

/*------------------------------------------------------------------------
 * pipread  --  Read from a pipe, blocking if empty
 *------------------------------------------------------------------------
 */
syscall	pipread(
		pipid32		pip,		/* ID of pipe to read from			*/
		char 		*buf,		/* pointer to buffer to read to		*/
		uint32		len			/* number of bytes to read 			*/
	)
{
	intmask	mask;				/* saved interrupt mask				*/

	mask = disable();

	if (isbadpip(pip)) {
		restore(mask);
		return SYSERR;
	}
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_CONNECTED) {
		restore(mask);
		return SYSERR;
	}

	/* Wait for buffer to be ready for reading */
	if (wait(pipptr->prdsem) == SYSERR) {
		restore(mask);
		return SYSERR;
	}

	// do stuff here

	/* Signal that the buffer is ready for writing */
	signal(pipptr->pwrsem);

	restore(mask);
	return OK;
}
