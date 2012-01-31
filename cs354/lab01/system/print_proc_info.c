/* print_proc_info.c - print_proc_info */

#include <xinu.h>
#include <string.h>

syscall print_proc_info(pid32 pid)
{
    intmask mask;
    struct procent *prptr;
    
    // save interrupt mask
    mask = disable();

    // check if PID is valid
    if (isbadpid(pid))
    {
        return SYSERR;
    }
    
    // print PID information
    prptr = &proctab[pid];
    kprintf("%s %d %d %s\r\n", prptr->prname, prptr->prprio, prptr->prstate, prptr->prstkptr);

    // restore interrupt mask
    restore(mask);

    return OK;
}
