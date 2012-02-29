/* pipdisconnect.c - pipdisconnect */

#include <xinu.h>

/*------------------------------------------------------------------------
 * pipdisconnect  --  Disonnect a pipe by resetting the two process IDs
 *------------------------------------------------------------------------
 */
syscall	pipdisconnect(
	  	pipid32		pip			/* ID of pipe to disconnect	*/
	)
{
	intmask	mask;				/* saved interrupt mask		*/

	mask = disable();

	if (isbadpip(pip)) {
		restore(mask);
		return SYSERR;
	}
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_CONNECTED ||
		pipptr->powner != currpid) {
		restore(mask);
		return SYSERR;
	}

	pipptr->pstate = PIPE_USED;
	pipptr->pend1 = 0;
	pipptr->pend2 = 0;

	restore(mask);
	return OK;
}
