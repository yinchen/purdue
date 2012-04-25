#include<xinu.h>

status rmDir(char *path)
{
	char pathTokens[LF_PATH_DEPTH][LF_NAME_LEN];  
	int pathDepth = tokenize(path,pathTokens);
	int lfnext = SYSERR;
	if(pathDepth == SYSERR)
	{
		return SYSERR;
	}
	if(1 == pathDepth && PATH_SEPARATOR==pathTokens[0][0])
	{
		return SYSERR;
	}
	wait(lfDirCblkMutex);
	
	
	if(moveToDir(pathTokens,pathDepth) == SYSERR)
	{
		signal(lfDirCblkMutex);
		return SYSERR;
	}

	struct lflcblk * dirCblk = &lfltab[Nlfl+1];	
	struct lflcblk tempCblk;
	struct lflcblk* fileCblk = &tempCblk;
	struct lflcblk* parentDirCblk = &lfltab[Nlfl];
	struct dentry devPtr;
	struct dentry parentDevPtr;
	struct ldentry tempEntry;
	struct ldentry *dirEntry = &tempEntry;
	devPtr.dvminor=Nlfl+1;	
	parentDevPtr.dvminor=Nlfl;	
	bool8 isRemaining = (bool8)0;	
	/*
	 * Find out the entry of the directory in the parent directory.
	 */
	while(lflRead(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == sizeof(struct ldentry))
	{
		if(!dirEntry->isUsed )
		{
			continue;
		}
		if( LF_TYPE_DIR == dirEntry->type )
		{	
			/*Trying to delete directory	*/
			if(dirEntry->ld_size > 0)
			{
				isRemaining = (bool8)1;
			}
			continue;
		}
		
		strcpy(pathTokens[pathDepth],dirEntry->ld_name);
		/*Don't delete a directory if some of the children files
		 * are still open
		 */
		if(isFileOpen(pathTokens,pathDepth+1,&lfnext))
		{
			isRemaining = (bool8)1;
			continue;
		}
		//Truncate the file
		resetLflCblk(fileCblk);
		fileCblk->lfstate = LF_USED;
		fileCblk->firstIbId = dirEntry->ld_ilist;
		fileCblk->fileSize = dirEntry->ld_size;
		wait(Lf_data.lf_mutex);
		lftruncate(fileCblk);
		fileCblk->lfstate = LF_FREE;
		signal(Lf_data.lf_mutex);
		memset(dirEntry->ld_name,NULLCH,LF_NAME_LEN);
		dirEntry->isUsed = (bool8)0;
		dirEntry->ld_ilist = LF_INULL;
		dirEntry->ld_size = 0;
		
		/*
		 * Update the entry in the parent directory.
		 */
		if(lflSeek(&devPtr,dirCblk->lfpos - sizeof(struct ldentry)) == SYSERR)
		{
			dirCblk->lfstate = LF_FREE;
			fileCblk->lfstate = LF_FREE;
			parentDirCblk->lfstate = LF_FREE;
			signal(lfDirCblkMutex);
			return SYSERR;
		}
		if(lflWrite(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == SYSERR)
		{
			dirCblk->lfstate = LF_FREE;
			fileCblk->lfstate = LF_FREE;
			parentDirCblk->lfstate = LF_FREE;
			signal(lfDirCblkMutex);
			return SYSERR;
		}
	}	
	if(lfflush(dirCblk) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		signal(lfDirCblkMutex);
		return SYSERR;
	}
	/*
	 * Can't delete the directory if some of the files/directory
	 * couldn't get deleted.
	 */

	if(isRemaining)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		signal(lfDirCblkMutex);
		return SYSERR;
	}
	/*All the files in the directory are deleted
	 * and there are no directories inside it.
	 * so we can delete this directory.
	 */
		
	wait(Lf_data.lf_mutex);
	lftruncate(dirCblk);
	signal(Lf_data.lf_mutex);

	dirCblk->lfstate = LF_FREE;
	/*Modify this directory's entry in its parent directory*/
	if(LF_FREE != parentDirCblk->lfstate)
	{		
		struct ldentry parentDirEntry;
		memset(dirEntry->ld_name,NULLCH,LF_NAME_LEN);
		parentDirEntry.isUsed = (bool8)0;
		parentDirEntry.ld_ilist = LF_INULL;
		parentDirEntry.ld_size = 0;
	
		if(SYSERR == lflSeek(&parentDevPtr, parentDirCblk->lfpos- sizeof(struct ldentry)))
		{
			parentDirCblk->lfstate = LF_FREE;
			signal(lfDirCblkMutex);
			return SYSERR;
		}
		if(SYSERR == lflWrite(&parentDevPtr,(char*)&parentDirEntry,sizeof(struct ldentry)))
		{
			parentDirCblk->lfstate = LF_FREE;
			signal(lfDirCblkMutex);
			return SYSERR;

		}
		if(SYSERR == lfflush(parentDirCblk))
		{
			parentDirCblk->lfstate = LF_FREE;
			signal(lfDirCblkMutex);
			return SYSERR;
		}
	}
	parentDirCblk->lfstate = LF_FREE;
	signal(lfDirCblkMutex);
	return OK;
}
