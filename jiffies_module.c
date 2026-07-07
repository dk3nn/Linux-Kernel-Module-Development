#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 128
#define PROC_NAME "jiffies"

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static const struct proc_ops proc_ops = {
        .proc_read = proc_read,
};

int proc_init(void)
{

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
        int len;
        char buffer[BUFFER_SIZE];

        if (*pos > 0) {
                return 0;
        }


        len = snprintf(buffer, BUFFER_SIZE, "Current jiffies = %lu\n", jiffies);
        if(copy_to_user(usr_buf, buffer, len))
                  return -EFAULT;
        
        *pos = len;
        return len;
}

module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("/proc/jiffies Module");
MODULE_AUTHOR("SGG");
