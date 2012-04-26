#include<xinu.h>

status moveToDir(char pathTokens[][LF_NAME_LEN],int fileDepth)
{
	struct lflcblk * dirCblk = &lfltab[Nlfl+1];	/*last entry is used for modifying the directory in which file is getting created.*/
	struct lflcblk* parentDirCblk = &lfltab[Nlfl];	/*second last entry is used for parent of the directory in which file is getting created*/
	struct dentry devPtr;
	struct dentry parentDevPtr;
	/*first read the  0th data block to find out 
	 * size of the root directory and first index block*/
	wait(Lf_data.lf_mutex);
	if(Lf_data.lf_dirpresent == FALSE)
	{
		/*Cache the root directory*/
		/*This should get executed only once*/
		struct  lfdir rootInfo;
		if(read(Lf_data.lf_dskdev,(char*)&rootInfo,LF_AREA_ROOT) == SYSERR)
		{
			signal(Lf_data.lf_mutex);
			return SYSERR;
		}
		Lf_data.lf_dir = rootInfo;
		Lf_data.lf_dirpresent = TRUE;
		Lf_data.lf_dirdirty = FALSE;
	}
	signal(Lf_data.lf_mutex);
	
	
	devPtr.dvminor=Nlfl+1;	
	parentDevPtr.dvminor=Nlfl;	
	/*Point to the root directory*/
	resetLflCblk(dirCblk);
	resetLflCblk(parentDirCblk);
	dirCblk->lfstate = LF_USED;
	dirCblk->lfsize = Lf_data.lf_dir.lfd_size;
	dirCblk->lffirstib = Lf_data.lf_dir.lfd_ifirst;
	
	int currentDepth =0;		/*Root directory has a depth of zero. */
	struct ldentry currentDirEntry;
	struct ldentry*dirEntry = &currentDirEntry;
	/*
	 * Start from the root and keep on going down unless dirCblk points
	 * to last directory in the tokenized path and parentDirCblk points
	 * to its parent.
	 */
	while(currentDepth < fileDepth && lflRead(&devPtr,(char*)dirEntry,sizeof(struct ldentry)) == sizeof(struct ldentry))
	{
		if(strcmp(dirEntry->ld_name,pathTokens[currentDepth])&& dirEntry->ld_used)
		{
			/*
			 * Return error if something in the path
			 * is directory instead of a file.
			 */
			if(dirEntry->ld_type != LF_TYPE_DIR)
			{
				return SYSERR;
			}
			/*
			 * Save the parent of the current directory.
			 */
			memcpy(parentDirCblk,dirCblk,sizeof(struct lflcblk));
			
			/*Read this directory*/
			resetLflCblk(dirCblk);
			dirCblk->lfstate = LF_USED;
			dirCblk->lfsize = dirEntry->ld_size;
			dirCblk->lffirstib = dirEntry->ld_ilist;
			++currentDepth;
		}
	}
	if(fileDepth != currentDepth)
	{
		return SYSERR;
	}
	
	return OK;
}
void resetLflCblk(struct lflcblk*dirCblk )
{
	dirCblk->lfstate = LF_FREE;
	dirCblk->lfpos     = 0;
	dirCblk->lfinum    = LF_INULL;
	dirCblk->lfdnum    = LF_DNULL;
	dirCblk->lfbyte =   &dirCblk->lfdblock[LF_BLKSIZ];
	dirCblk->lfibdirty = FALSE;
	dirCblk->lfdbdirty = FALSE;
	dirCblk->lfsize = -1;
	dirCblk->lffirstib = LF_INULL;
	memset((char*)dirCblk->lfpath,NULLCH,LF_PATH_DEPTH*LF_NAME_LEN);
	dirCblk->lfdepth = -1;
}
