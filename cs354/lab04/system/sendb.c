/* sendb.c - sendb */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  sendb  -  pass a message to a process and start recipient if waiting
 *            using blocking
 *------------------------------------------------------------------------
 */
syscall	sendb(
	  pid32		pid,					/* ID of recipient process		*/
	  umsg32	msg						/* contents of message			*/
	)
{
	intmask	mask;						/* saved interrupt mask			*/
	struct	procent *prptr;				/* ptr to process' table entry	*/
	struct	procent *sndprptr;			/* ptr to process' table entry	*/

	mask = disable();					/* save interrupts				*/
	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR;
	}

	prptr = &proctab[pid];				/* check pid and prstate		*/
	if (prptr->prstate == PR_FREE) {
		restore(mask);
		return SYSERR;
	}

	pid32 sndpid = currpid();			/* get sending process id 		*/
	sndprptr = &proctab[sndpid];		/* get sending process entry	*/

	if (prptr->prhasmsg) {
		sndprptr->sndmsg = msg;			/* hold message					*/
		sndprptr->sndflag = TRUE;		/* indicate message is sending	*/

		sndprptr->prstate = PR_SND;		/* put process in sending state */
		insert(sndpid, sendlist, 0);	/* put process in sending queue */

		resched();						/* block process				*/
	}
	else {
		prptr->prmsg = msg;				/* deliver message 				*/
		prptr->prhasmsg = TRUE;			/* indicate message is waiting 	*/
	}

	restore(mask);						/* restore interrupts 			*/
	return OK;
}
