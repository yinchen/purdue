/* pipcreate.c - pipcreate, newpip */

#include <xinu.h>

local	pipid32	newpip(void);

/*------------------------------------------------------------------------
 *  pipcreate  -  create a new pipe and return the ID to the caller
 *------------------------------------------------------------------------
 */
pipid32	pipcreate(void)
{
	pipid32	pip;				/* pipe ID to return	*/

	if ((pip=newpip())==SYSERR) {
		return SYSERR;
	}
	piptab[pip].powner = currpid;	/* initialize table entry	*/

	return pip;
}

/*------------------------------------------------------------------------
 *  newpip  -  allocate an unused pipe and return its index
 *------------------------------------------------------------------------
 */
local	pipid32	newpip(void)
{
	static	pipid32	nextpip = 0;	/* next pipe index to try	*/
	pipid32	pip;					/* pipe ID to return	*/
	int32	i;						/* iterate through # entries	*/

	for (i=0 ; i<NPIPE ; i++) {
		pip = nextpip++;
		if (nextpip >= NPIPE)
			nextpip = 0;
		if (piptab[pip].pstate == PIPE_FREE) {
			piptab[pip].pstate = PIPE_USED;
			return pip;
		}
	}
	return SYSERR;
}
