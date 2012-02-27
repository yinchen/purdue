/* pipdelete.c - pipdelete */

#include <xinu.h>

/*------------------------------------------------------------------------
 * pipdelete  --  Delete a pipe by releasing its table entry
 *------------------------------------------------------------------------
 */
syscall	pipdelete(
	  pipid32	pip			/* ID of semaphore to delete	*/
	)
{
	if (isbadpip(pip)) {
		return SYSERR;
	}
	
	pipptr = &piptab[pip];
	if (pipptr->powner != currpid) {
		return SYSERR;
	}
	if (pipptr->pstate == PIPE_FREE) {
		return SYSERR;
	}
	pipptr->pstate = PIPE_FREE;

	return OK;
}
