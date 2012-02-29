/* pipdelete.c - pipdelete */

#include <xinu.h>

/*------------------------------------------------------------------------
 * pipdelete  --  Delete a pipe by releasing its table entry
 *------------------------------------------------------------------------
 */
syscall	pipdelete(
	 	pipid32		pip			/* ID of semaphore to delete	*/
	)
{
	intmask	mask;				/* saved interrupt mask			*/

	mask = disable();

	if (isbadpip(pip)) {
		restore(mask);
		return SYSERR;
	}
	
	pipptr = &piptab[pip];
	if (pipptr->pstate != PIPE_USED ||
		pipptr->powner != currpid) {
		restore(mask);
		return SYSERR;
	}

	pipptr->pstate = PIPE_FREE;
	pipptr->powner = 0;
	pipptr->prdsem = semdelete(pipptr->prdsem);
	pipptr->pwrsem = semdelete(pipptr->pwrsem);

	restore(mask);
	return OK;
}
