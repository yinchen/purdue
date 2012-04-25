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
        
        lflistdir(LFILESYS);

        file = open(LFILESYS, "AAA", "rw");
        write(file, "MATT\0", 5);
        close(file);
        
        file = open(LFILESYS, "BBB", "rw");
        write(file, "MATT\0", 5);
        close(file);
        
        file = open(LFILESYS, "CCC", "rw");
        write(file, "MATT\0", 5);
        close(file);
        
        file = open(LFILESYS, "DDD", "rw");
        write(file, "MATT\0", 5);
        close(file);
        
        lflistdir(LFILESYS);

	return OK;
}
