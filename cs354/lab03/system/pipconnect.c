/* pipconnect.c - pipconnect */

#include <xinu.h>

/*------------------------------------------------------------------------
 * pipconnect  --  Connect a pipe by setting the two process IDs
 *------------------------------------------------------------------------
 */
syscall	pipconnect(
	  	pipid32		pip,		/* ID of pipe to connect	*/
	  	pid32		end1,		/* ID of process 1			*/
	  	pid32		end2		/* ID of process 2			*/
	)
{
	intmask	mask;				/* saved interrupt mask		*/

	mask = disable();

	if (isbadpip(pip)) {
		restore(mask);
		return SYSERR;
	}

	struct pentry *pipptr;		/* ptr to pipe table entry	*/
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_USED ||
		pipptr->powner != getpid()) {
		restore(mask);
		return SYSERR;
	}

	pipptr->pstate = PIPE_CONNECTED;
	pipptr->pend1 = end1;
	pipptr->pend2 = end2;

	restore(mask);
	return OK;
}
