/* print_proc_info.c - print_proc_info */

#include <xinu.h>
#include <string.h>

syscall print_proc_info(pid32 pid)
{
    // save interrupt mask
    intmask mask; // saved interrupt mask
    mask = disable();
    
    if ((ssize < MINSTK) || 
        (priority <= 0) || 
        (((int32)(pid = newpid())) == (int32) SYSERR) || 
        ((saddr = (uint32 *)getstk(ssize)) == (uint32 *)SYSERR))
    {
        return SYSERR;
    }

	prcount++;
	prptr = &proctab[pid];

    restore(mask);
}

