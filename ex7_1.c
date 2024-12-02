#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>

// Our thread
static struct task_struct *thread;

// Our thread function
int thread_function(void *args)
{
    printk(KERN_INFO "I'm a thread!\n");
    return 0;
}

static int __init init_mod(void)
{
    printk(KERN_INFO "I'm a module!\n");
    // Create thread
    // *** COMPLETE ME ***
    thread = kthread_run(thread_function, NULL,"Module Thread");
    if (thread)
    {
        printk(KERN_INFO "Thread created\n");
    }
    else 
    {
        printk(KERN_INFO "Thread creation failed\n");
        return 1;
    }
    return 0;
}

static void __exit exit_mod(void)
{
    printk(KERN_INFO "Exiting...\n");
}

// Set module initialisation function
// *** COMPLETE ME ***
module_init(init_mod);
// Set module exit function
// *** COMPLETE ME ***
module_exit(exit_mod);
// Set module license to GPL
// *** COMPLETE ME ***
MODULE_LICENSE("GPL");
// Set module author
// *** COMPLETE ME ***
MODULE_AUTHOR("Krystian Mowinski  <Mowinskk@gmail.com>");
// Set module description
// *** COMPLETE ME ***
MODULE_DESCRIPTION("A simple module");