/* pipwrite.c - pipwrite */

#include <xinu.h>

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
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_CONNECTED) {
		restore(mask);
		return SYSERR;
	}

	// do stuff here

	restore(mask);
	return OK;
}
