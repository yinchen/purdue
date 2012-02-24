/* pipe.h - isbadpip */

/* Maximum number of pipes for a process */

#ifndef NPIPE
#define	NPIPE			10
#endif		

/* Process state constants */

#define	PIPE_FREE		0	/* pipe is unused	*/
#define	PIPE_USED		1	/* pipe has been allocated		*/
#define	PIPE_CONNECTED	2	/* pipe is connected and in use		*/

/* Miscellaneous pipe definitions */

#define	PIPE_SIZ		256	/* size of pipe buffer		*/

/* Definition of the pipe (multiple of 32 bits) */

struct pentry {		/* entry in the pipe table		*/
	uint16	pstate;	/* pipe state: PIPE_FREE, etc.		*/
	char	pbuf[PIPE_SIZ];	/* pipe buffer			*/
	pid32	powner;	/* id of the owner process		*/
	pid32	preader;	/* id of the reading process		*/
	pid32	pwriter;	/* id of the writing process		*/
};

extern	struct	pentry piptab[];

#define	isbadpip(p)	((int32)(p) < 0 || (p) >= NPIPE)
