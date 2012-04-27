/* lfsOpen.c  -  lfsOpen */

#include <xinu.h>

status lfsOpenHelper(char *fileName,struct ldentry *dirEntry,int32 modeBits);

/*------------------------------------------------------------------------
 * lfsOpen - open a file and allocate a local file pseudo-device
 *------------------------------------------------------------------------
 */
devcall	lfsOpen (
	 struct	dentry	*devptr,	/* entry in device switch table	*/
	 char	*path,			/* complete path of file to open		*/
	 char	*mode			/* mode chars: 'r' 'w' 'o' 'n'	*/
	)
{
	did32		lfnext;		/* minor number of an unused	*/
					/*    file pseudo-device	*/
	struct	lflcblk	*lfptr;		/* ptr to open file table entry	*/
	int32	mbits;			/* mode bits			*/


	char pathTokens[LF_PATH_DEPTH][LF_NAME_LEN];  
	int pathDepth = tokenize(path,pathTokens);
	if (pathDepth == SYSERR)
	{
		return SYSERR;
	}
	if (1 == pathDepth && PATH_SEPARATOR==pathTokens[0][0])
	{
		return SYSERR;
	}
	/* Parse mode argument and convert to binary */

	mbits = lfgetmode(mode);
	if (mbits == SYSERR) {
		return SYSERR;
	}

	/* If named file is already open, return SYSERR */

	lfnext = SYSERR;
	wait(lfDirCblkMutex);
	if (isopenfile(pathTokens,pathDepth,&lfnext))
	{
		signal(lfDirCblkMutex);
		return SYSERR;
	}
	if (lfnext == SYSERR) {	/* no slave file devices are available	*/
		signal(lfDirCblkMutex);
		return SYSERR;
	}

	struct ldentry fileInfo;
	/*
	 * Initialize lfltab[Nlfl+1] and lfltab[Nlfl]
	 * to parent and grandparent of the file we
	 * want to open.
	 * e.g. to /a/b and to /a/ if we want to open
	 * /a/b/c.
	 */
 	if (mvdir(pathTokens,pathDepth-1) == SYSERR)
	{
		signal(lfDirCblkMutex);
		return SYSERR;
	}	
	/*
	 * Either create a  new file or open an already existing file.
	 */
	if (lfsOpenHelper(pathTokens[pathDepth-1],&fileInfo,mbits) == SYSERR)
	{
		signal(lfDirCblkMutex);
		return SYSERR;
	}
	

	/* Initialize the local file pseudo-device */
	lfptr = &lfltab[lfnext];
	lfptr->lfstate = LF_USED;
	lfptr->lfmode = mbits & LF_MODE_RW;

	/* File starts at position 0 */

	lfptr->lfpos     = 0;

	/* Neither index block nor data block are initially valid	*/

	lfptr->lfinum    = LF_INULL;
	lfptr->lfdnum    = LF_DNULL;

	/* Initialize byte pointer to address beyond the end of the	*/
	/*	buffer (i.e., invalid pointer triggers setup)		*/

	lfptr->lfbyte = &lfptr->lfdblock[LF_BLKSIZ];
	lfptr->lfibdirty = FALSE;
	lfptr->lfdbdirty = FALSE;

	lfptr->lfsize = fileInfo.ld_size;
	lfptr->lffirstib = fileInfo.ld_ilist;
	memcpy(lfptr->lfpath,pathTokens,LF_NAME_LEN * LF_PATH_DEPTH);
	lfptr->lfdepth = pathDepth;

	signal(lfDirCblkMutex);
	return lfptr->lfdev;
}
/*
 * Assumes that parent and grandparent are already initialized
 * and fileName points to the name of the file.
 * dirEntry is initialized ot the entry of the file in the 
 * parent directory.
 */
status lfsOpenHelper(char *fileName,struct ldentry *dirEntry,int32 mbits)
{
	struct lflcblk * dirCblk = &lfltab[Nlfl+1];	/*last entry is used for modifying the directory in which file is getting created.*/
	struct lflcblk* parentDirCblk = &lfltab[Nlfl];	/*second last entry is used for parent of the directory in which file is getting created*/
	struct dentry devPtr;
	struct dentry parentDevPtr;
	devPtr.dvminor=Nlfl+1;	
	parentDevPtr.dvminor=Nlfl;	
	uint32 replacePos = 0;
	bool8 isRPosInitialized = 0;
	
	while(lflRead(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == sizeof(struct ldentry))
	{
		if (!dirEntry->ld_used)
		{
			if (!isRPosInitialized)
			{
				replacePos = dirCblk->lfpos - sizeof(struct ldentry);
				isRPosInitialized = 1;
			}
			continue;
		}
		/*
		 * We found a match.
		 */
		if (strcmp(dirEntry->ld_name,fileName) && dirEntry->ld_used)
		{
			if ( LF_TYPE_DIR == dirEntry->ld_type)
			{	
				/*Trying to open a directory	*/
				dirCblk->lfstate = LF_FREE;
				parentDirCblk->lfstate = LF_FREE;
				return SYSERR;
			}
			if (mbits & LF_MODE_N) 
			{	/* file must not exist	*/
				dirCblk->lfstate = LF_FREE;
				parentDirCblk->lfstate = LF_FREE;
				return SYSERR;
			}
			dirCblk->lfstate = LF_FREE;
			parentDirCblk->lfstate = LF_FREE;
			return OK;
		}
	}
	//File Not Found
	/*
	 * If we are opening a file and file doesn't exist
	 * then return error.
	 */
	if (mbits & LF_MODE_O)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	/*
	 * If the file doesn't exist and mode bits have
	 * LF_MODE_N set then create the file.
	 */
	if (isRPosInitialized)
	{
		/*
		 * We can reuse an existing directory entry to create
		 * new file.
		 */
		lflSeek(&devPtr,replacePos);
	}
	/*
	 * Create the file
	 */
	if (SYSERR == touchdir(fileName,LF_TYPE_FILE,dirEntry,isRPosInitialized))
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	return OK;
}






