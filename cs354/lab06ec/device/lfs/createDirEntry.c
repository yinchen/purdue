#include<xinu.h>


/*
 * Creates an entry for file/directory in the directory currently loaded in
 * lfltab[Nllfl+1] and updates the size of the parent directory.
 * name is the name of the file/directory,type identifies whether we are
 * creating a file or directory and isReplace tells us whether we are updating
 * an existing unused entry or adding a new entry
 */
status createDirEntry(char*name,byte type,struct ldentry*dirEntry,bool8 isReplace)
{
	struct lflcblk * dirCblk = &lfltab[Nlfl+1];	/*last entry is used for modifying the directory in which file is getting created.*/
	struct lflcblk* parentDirCblk = &lfltab[Nlfl];	/*second last entry is used for parent of the directory in which file is getting created*/
	struct dentry devPtr;
	struct dentry parentDevPtr;

	devPtr.dvminor=Nlfl+1;	
	parentDevPtr.dvminor=Nlfl;	

	/*
	 * Initialize the entry
	 */
	dirEntry->ld_size = 0;
	dirEntry->ld_ilist = LF_INULL;
	dirEntry->ld_type = type;
	dirEntry->ld_used = true;
	strcpy(dirEntry->ld_name,name);

	if(lflWrite(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	/*Close the current directory*/
	if(lfflush(dirCblk) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	/*
	 * If we reused an existing entry then we are done.
	 */
	if(isReplace)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return OK;
	}
	/* 
	 * Othewise increment the size of the parent directory
	 */
	/*
	 * entry got added in the root directory so there is no
	 * grandparent.
	 */
	if(LF_FREE == parentDirCblk->lfstate)
	{
		/*One entry got added to the root directory*/
		dirCblk->lfstate = LF_FREE;

		wait(Lf_data.lf_mutex);
		Lf_data.lf_dir.lfd_size += sizeof(struct ldentry);
		Lf_data.lf_dirdirty = TRUE;
		signal(Lf_data.lf_mutex);
		return OK;
	}
	
	/*As we have created a new entry in this non-root directory update its entry in
	 * the parent directory to reflect the increased size of this directory.
	 * The lfPos of the parent directory is pointing to the location just
	 * after this directory's entry.
	 */
	
	struct ldentry parentDirEntry;
	/*
	 * Move to the poistion in grandparent at which the entry for the parent
	 * begins.
	 */
	lflSeek(&parentDevPtr,parentDirCblk->lfpos - sizeof(struct ldentry));
	if(lflRead(&parentDevPtr,(char*)&parentDirEntry,sizeof(struct ldentry)) ==SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	/*
	 * Update that entry.
	 */
	parentDirEntry.ld_size += sizeof(struct ldentry);
	parentDirEntry.ld_ilist = dirCblk->lffirstib;
	
	/* 
	 * As we have just read that entry move back again so that 
	 * we can overwrite it.
	 */
	lflSeek(&parentDevPtr,parentDirCblk->lfpos - sizeof(struct ldentry));
	
	/*
	 * Write to the grandparent.
	 */
	if(lflWrite(&parentDevPtr,(char*)&parentDirEntry,sizeof(struct ldentry)) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		return SYSERR;
	}
	/*Close the parent directory*/
	if(lfflush(parentDirCblk) == SYSERR)
	{
		dirCblk->lfstate = LF_FREE;
		parentDirCblk->lfstate = LF_FREE;
		
		return SYSERR;
	}
	dirCblk->lfstate = LF_FREE;
	parentDirCblk->lfstate = LF_FREE;
	return OK;
}

