#include <linux/kernel.h> 
#include <linux/unistd.h>

void sys_my_stack_trace() { 
	dump_stack();
}

