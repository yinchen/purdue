/* pipwrite.c - pipwrite */

#include <xinu.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * pipwrite  --  Write to a pipe, blocking if full
 *------------------------------------------------------------------------
 */
syscall	pipwrite(
		pipid32		pip,		/* ID of pipe to write to			*/
		char 		*buf,		/* pointer to buffer to write from	*/
		uint32		len			/* number of bytes to write			*/
	)
{
	intmask	mask;				/* saved interrupt mask				*/

	mask = disable();

	if (isbadpip(pip)) {
		restore(mask);
		return SYSERR;
	}

	struct pentry *pipptr;		/* ptr to pipe table entry			*/
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_CONNECTED ||
		(pipptr->pend1 != getpid() && pipptr->pend2 != getpid())) {
		restore(mask);
		return SYSERR;
	}

	/* Wait for buffer to be ready for writing */
	if (wait(pipptr->pwrsem) == SYSERR) {
		restore(mask);
		return SYSERR;
	}

	char *buffer = buf;			/* local copy of buffer				*/
	int count = 0;				/* character count for buffer		*/

	/* Write characters to the circular buffer */
	while (count < len)
	{
		pipptr->pbuf[(pipptr->pbufs + pipptr->pbufc) % PIPE_SIZ] = *buffer++;
		count++;
		pipptr->pbufc++;

		kprintf("A\r\n");
	}

	/* Signal that the buffer is ready for reading */
	signal(pipptr->prdsem);

	restore(mask);
	return OK;
}
