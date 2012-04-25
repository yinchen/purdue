/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/*									*/
/* main - main program for testing Xinu					*/
/*									*/
/************************************************************************/

int main(int argc, char **argv)
{
	int32	retval;
	int i; 
	did32 file = 0;

	/* Obtain network configuration from DHCP server */

	NetData.ipvalid = FALSE;
	retval = getlocalip();
	if (retval == SYSERR) 
		panic("Error: could not obtain an IP address\n\r");

	/* Open the remote disk */

	retval = open(RDISK,"XinuDisk","rw");
	if (retval == SYSERR)
		panic("Error: could not open the remote disk, check the server\n\r");

	kprintf("\n\r**********************************************************\n\r");

	/* Testing lflistdir */

	for (i = 0; i < Nlfl; i++) {
        	if (lfltab[i].lfstate == LF_USED) {
             		kprintf("Files open on this system, cannot format\r\n");
                    	return SYSERR;
             	}
        }                        

        if (lfscreate(Lf_data.lf_dskdev, 100, 500*512) == SYSERR){
        	kprintf("Creating the filesystem failed\r\n");
                return SYSERR;
        }
        
        /* print initial directory listing */
        lflistdir(LFILESYS);

	/* write file #1 to disk */
        file = open(LFILESYS, "AAA", "rw");
        if (file == SYSERR) {
	        kprintf("File open failed for AAA\r\n");
	        return SYSERR;
	}
	
	// close(file);
        
        /* write file #2 to disk */
        file = open(LFILESYS, "BBB", "rw");
        if (file == SYSERR) {
	        kprintf("File open failed for AAA\r\n");
	        return SYSERR;
	}
	
	// close(file);
	
	/* write file #3 to disk */
        file = open(LFILESYS, "CCC", "rw");
        if (file == SYSERR) {
	        kprintf("File open failed for AAA\r\n");
	        return SYSERR;
	}
	
	// close(file);
	
	/* write file #4 to disk */
        file = open(LFILESYS, "DDD", "rw");
        if (file == SYSERR) {
	        kprintf("File open failed for AAA\r\n");
	        return SYSERR;
	}
	
	// close(file);
        
        lflistdir(LFILESYS);

	return OK;
}
