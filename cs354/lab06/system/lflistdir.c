/* lflistdir.c - lflistdir */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  lflistdir  -  List all valid files within the XINU flat file system
 *------------------------------------------------------------------------
 */
syscall	lflistdir(
		did32	diskdev			/* ID of device to read from	*/
	)
{
	intmask			mask;		/* saved interrupt mask			*/
	int32			retval;		/* value to return to caller	*/

	struct dentry 	*devptr;	/* entry in device switch table	*/
	
	mask = disable();
	if (isbaddev(diskdev)) {
		restore(mask);
		return SYSERR;
	}

	devptr = (struct dentry *) &devtab[diskdev];

	/* obtain copy of directory if not already in memory 		*/

	struct	lfdir	*dirptr;	/* ptr to in-memory directory	*/
	
	dirptr = &Lf_data.lf_dir;
	wait(Lf_data.lf_mutex);
	if (! Lf_data.lf_dirpresent)
	{
	    retval = read(Lf_data.lf_dskdev, (char *)dirptr,LF_AREA_DIR);
	    if (retval == SYSERR )
	    {
			signal(Lf_data.lf_mutex);
			return SYSERR;
	    }
	    
	    Lf_data.lf_dirpresent = TRUE;
	}

	/* list all files in directory */

	if (dirptr->lfd_nfiles == 0)
	{
		kprintf("No files\r\n");
		return OK;
	}

	int32		i;		/* general loop index		*/
	struct	ldentry	*ldptr;		/* ptr to an entry in directory	*/

	for (i = 0; i < dirptr->lfd_nfiles; i++)
	{
		ldptr = &dirptr->lfd_files[i];
		kprintf("%s\r\n", ldptr->ld_name);
	}

	return OK;
}
