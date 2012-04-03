/* receiveb.c - receiveb */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  receiveb  -  wait for a message and return the message to the caller
 *               using blocking
 *------------------------------------------------------------------------
 */
umsg32	receiveb(void)
{
	intmask	mask;						/* saved interrupt mask			*/
	struct	procent *prptr;				/* ptr to process' table entry	*/
	struct	procent *sndprptr;			/* ptr to process' table entry	*/
	umsg32	msg;						/* message to return			*/

	mask = disable();

	prptr = &proctab[currpid];
	if (prptr->prhasmsg == FALSE) {
		pid32 sndpid = dequeue(prptr->sndqueue);

		if (sndpid != EMPTY) {
			sndprptr = &proctab[sndpid];		/* get sending process entry	*/
			msg = sndprptr->sndmsg;				/* retrieve message				*/
			sndprptr->sndflag = FALSE;			/* reset message flag			*/

			ready(sndpid, RESCHED_YES);
		} 
		else {
			prptr->prstate = PR_RECV;
			resched();						/* block until message arrives	*/
		}
	}

	msg = prptr->prmsg;					/* retrieve message				*/
	prptr->prhasmsg = FALSE;			/* reset message flag			*/

	restore(mask);
	return msg;
}
