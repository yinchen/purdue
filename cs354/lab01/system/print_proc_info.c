/* print_proc_info.c - print_proc_info */

#include <xinu.h>
#include <string.h>

syscall print_proc_info(pid32 pid)
{
    // save interrupt mask
    intmask mask; // saved interrupt mask
    mask = disable();
    
    
    prptr = &proctab[pid];
	if (prptr == NULL)
	{
	    return SYSERR;
	}
	
	kprintf(prptr->prname);
	kprintf(" ");
	kprintf(prptr->prprio);
	kprintf(" ");
	kprintf(prptr->prstate);
	kprintf(" ");
	kprintf(prptr->prstkptr);
	kprintf("\n");

    restore(mask);
}

