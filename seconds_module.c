#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/jiffies.h>
#include <asm/param.h>
#include <linux/uaccess.h>

#define PROC_NAME "seconds"
static unsigned long start_jiffies;

static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static const struct proc_ops proc_ops = {
        .proc_read = proc_read,
};

int proc_init(void)
{
        start_jiffies = jiffies;
        
        proc_create(PROC_NAME, 0666, NULL, &proc_ops);

        printk(KERN_INFO "/proc/%s created\n", PROC_NAME);

	return 0;
}

void proc_exit(void) {

        remove_proc_entry(PROC_NAME, NULL);

        printk( KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
        int rv;
        char buffer[128];
        unsigned long elapsed_sec;
        
        if (*pos > 0) {
              return 0;
        }

        
        elapsed_sec = (jiffies - start_jiffies)/HZ;
        rv = snprintf(buffer, sizeof(buffer), "Elapsed seconds = %lu\n", elapsed_sec);
        
        if (copy_to_user(usr_buf, buffer, rv))
              return -EFAULT;
        
        *pos = rv;
        return rv;
}


module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("/proc/seconds Module");
MODULE_AUTHOR("SGG");
