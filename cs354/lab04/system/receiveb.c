/* receiveb.c - receiveb */

#include <xinu.h>
#include <stdio.h>

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

	kprintf("DEBUG: receiveb.c:20\r\n");

	prptr = &proctab[currpid];
	if (prptr->prhasmsg == FALSE) {
		kprintf("DEBUG: receiveb.c:24\r\n");

		pid32 sndpid = dequeue(prptr->sndqueue);

		if (sndpid != EMPTY) {
			kprintf("DEBUG: receiveb.c:29\r\n");

			sndprptr = &proctab[sndpid];		/* get sending process entry	*/
			msg = sndprptr->sndmsg;				/* retrieve message				*/
			sndprptr->sndflag = FALSE;			/* reset message flag			*/

			ready(sndpid, RESCHED_YES);
		} 
		else {
			kprintf("DEBUG: receiveb.c:38\r\n");

			prptr->prstate = PR_RECV;
			resched();						/* block until message arrives	*/
		}
	}

	kprintf("DEBUG: receiveb.c:45\r\n");

	msg = prptr->prmsg;					/* retrieve message				*/
	prptr->prhasmsg = FALSE;			/* reset message flag			*/

	restore(mask);
	return msg;
}
