#include <linux/kernel.h> 
#include <linux/unistd.h>
#include <linux/sched.h>

void sys_my_get_proc_name_by_id(int pid, char *user_buff) {
	// Get task_struct using pid
	struct task_struct *t;
	t = find_task_by_vpid(pid);
	
	// if task_struct is not NULL, Get executable name of the task
	if (t == NULL)
		return;
	
	char buf[17]; //size of exec name in Linux is 16. We add extra byte for NULL termination.

	get_task_comm(buf, t);
	buf[16] = '\0';
		
	// Copy the name of the task structure to user supplied buffer
	copy_to_user(user_buff, buf, 17);
 }

