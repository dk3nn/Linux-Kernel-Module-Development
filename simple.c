/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <linux/jiffies.h>
#include <asm/param.h>

static unsigned long my_number = 42;
module_param(my_number, ulong, 0644);
MODULE_PARM_DESC(my_number, "A number to display and use in calculations");

static char *my_name = "Kernel";
module_param(my_name, charp, 0644);
MODULE_PARM_DESC(my_name, "A name to display in log");

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module: Hello, %s!\n", my_name);
       
       printk(KERN_INFO "GOLDEN_RATIO_PRIME = %lu\n", GOLDEN_RATIO_PRIME);
       
       printk(KERN_INFO "Current jiffies = %lu\n", jiffies);
       
       printk(KERN_INFO "HZ = %lu\n", HZ);
       
       printk(KERN_INFO "Your number parameter = %lu\n", my_number);
       
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) 
{
       printk(KERN_INFO "Removing Module: Goodbye, %s!\n", my_name);
       
       printk(KERN_INFO "GCD of 3300 and 24 = %lu\n", gcd(3300UL, 24UL));
       
       printk(KERN_INFO "GCD of your number and 24 = %lu\n", gcd(my_number, 24UL));
       
       printk(KERN_INFO "Current jiffies = %lu\n", jiffies);
       
       
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

