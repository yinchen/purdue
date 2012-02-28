/* pipdisconnect.c - pipdisconnect */

#include <xinu.h>

/*------------------------------------------------------------------------
 * pipdisconnect  --  Disonnect a pipe by resetting the two process IDs
 *------------------------------------------------------------------------
 */
syscall	pipconnect(
	  pipid32	pip			/* ID of pipe to disconnect	*/
	)
{
	if (isbadpip(pip)) {
		return SYSERR;
	}
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_CONNECTED) {
		return SYSERR;
	}
	pipptr->pstate = PIPE_USED;
	pipptr->pend1 = 0;
	pipptr->pend2 = 0;

	return OK;
}
