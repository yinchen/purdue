/* lflClose.c  -  lflClose.c */

#include <xinu.h>

static status lflCloseHelper(char *fileName,struct lflcblk* lfptr);
/*------------------------------------------------------------------------
 * lflClose  --  close a file by flushing output and freeing device entry
 *------------------------------------------------------------------------
 */
devcall	lflClose (
	  struct dentry *devptr		/* entry in device switch table */
	)
{
	struct	lflcblk	*lfptr;		/* ptr to open file table entry	*/

	/* Obtain exclusive use of the file */

	lfptr = &lfltab[devptr->dvminor];
	wait(lfptr->lfmutex);

	/* If file is not open, return an error */

	if (lfptr->lfstate != LF_USED) {
		signal(lfptr->lfmutex);
		return SYSERR;
	}

	/* Write index or data blocks to disk if they have changed */

	if (lfptr->lfdbdirty || lfptr->lfibdirty) {
		lfflush(lfptr);
	}

	/*Update the file entry in parent directory*/
	wait(lfDirCblkMutex);

	if(moveToDir(lfptr->path,lfptr->depth-1) == SYSERR)
	{
		signal(lfDirCblkMutex);
		signal(lfptr->lfmutex);
		return SYSERR;
	}
	if(lflCloseHelper(lfptr->path[lfptr->depth-1],lfptr) == SYSERR)
	{
		signal(lfDirCblkMutex);
		signal(lfptr->lfmutex);
		return SYSERR;
	}
	/* Set device state to FREE and return to caller */

	lfptr->lfstate = LF_FREE;
	signal(lfDirCblkMutex);
	signal(lfptr->lfmutex);
	return OK;
}
static status lflCloseHelper(char *fileName,struct lflcblk* lfptr)
{
	struct lflcblk * dirCblk = &lfltab[Nlfl+1];	/*last entry is used for modifying the directory in which file is getting created.*/
	struct lflcblk* parentDirCblk = &lfltab[Nlfl];	/*second last entry is used for parent of the directory in which file is getting created*/
	struct dentry devPtr;
	struct dentry parentDevPtr;
	struct ldentry tempEntry;
	struct ldentry*dirEntry = &tempEntry;
	devPtr.dvminor=Nlfl+1;	
	parentDevPtr.dvminor=Nlfl;	
	bool8 found = 0;
	while(lflRead(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == sizeof(struct ldentry))
	{
		if(strcmp(dirEntry->ld_name,fileName) && dirEntry->isUsed)
		{
			found = 1;
			break;
		}
	}
	if(!found)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	
	dirEntry->ld_ilist = lfptr->firstIbId;
	dirEntry->ld_size = lfptr->fileSize;
	
	uint32 writePos = dirCblk->lfpos - sizeof(struct ldentry);
	
	lflSeek(&devPtr,writePos);

	if(lflWrite(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	
	/*Close the directory*/
	if(lfflush(dirCblk) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		
		return SYSERR;
	}
	dirCblk->lfstate = LF_FREE;
	parentDirCblk->lfstate = LF_FREE;
	
	return OK;

}
