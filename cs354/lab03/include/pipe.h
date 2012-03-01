/* pipe.h - isbadpip */

#define	NPIPE			10  		/* maximum number of pipes			*/

#define	PIPE_FREE		0			/* pipe is unused					*/
#define	PIPE_USED		1			/* pipe has been allocated			*/
#define	PIPE_CONNECTED	2			/* pipe is connected and in use		*/

#define	PIPE_SIZ		256			/* size of pipe buffer				*/

struct 	pentry {					/* entry in the pipe table			*/
		uint16	pstate;				/* pipe state (PIPE_FREE, etc.)		*/
		pid32	powner;				/* id of the owner process			*/
		pid32	pend1;				/* id of the end1 process			*/
		pid32	pend2;				/* id of the end2 process			*/
		sid32	prdsem;				/* reader semaphore					*/
		sid32	pwrsem;				/* writer semaphore					*/
		char	pbuf[PIPE_SIZ];		/* pipe buffer						*/
		int32	pbufs;				/* pipe buffer starting index		*/
		int32	pbufc;				/* pipe buffer character count		*/
};

extern	struct	pentry 	piptab[];	/* pipe table 						*/

#define	isbadpip(p)		((int32)(p) < 0 || (p) >= NPIPE)
