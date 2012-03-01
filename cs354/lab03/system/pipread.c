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

	struct pentry *pipptr;		/* ptr to pipe table entry			*/
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_CONNECTED ||
		(pipptr->pend1 != getpid() && pipptr->pend2 != getpid())) {
		restore(mask);
		return SYSERR;
	}

	/* Wait for buffer to be ready for reading */
	if (semcount(pipptr->prdsem) < len) {
		restore(mask);
		return SYSERR;
	}

	char *buffer = buf;			/* local copy of buffer				*/
	int count = 0;				/* character count for buffer		*/
	char c;						/* temporary holder for characters	*/

	/* Read characters from the circular buffer */
	while (count < len)
	{
		wait(pipptr->prdsem);

		kprintf("here4\r\n");

		c = pipptr->pbuf[pipptr->pbufs];

		kprintf("here5\r\n")

		*buffer++ = c;

		kprintf("here6\r\n")

		pipptr->pbufc--;

		kprintf("here7\r\n")

		pipptr->pbufs = (pipptr->pbufs + 1) % PIPE_SIZ;

		kprintf("here8\r\n")

		count++;

		kprintf("here9\r\n")

		signal(pipptr->pwrsem);
	}

	restore(mask);
	return count;
}
