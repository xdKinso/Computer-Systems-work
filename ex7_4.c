#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *thread;

int thread_function(void *args)
{
    int i = 0;
    // Loop until thread should stop
    // *** COMPLETE ME ***
    while (!kthread_should_stop())
    {
        printk(KERN_INFO "In thread function %d\n", ++i);
        // Sleep for 1000 milliseconds
        // *** COMPLETE ME ***
        msleep(1000);

    }
    printk(KERN_INFO "Thread exiting\n");
    return 0;
}

static int __init init_mod(void)
{
    // Create thread using kthread_create
    // *** COMPLETE ME ***
    thread = kthread_create(thread_function, NULL, "thread");
    // Bind thread to CPU 0
    // *** COMPLETE ME ***
    kthread_bind(thread, 0);
    // Wake up the thread
    // *** COMPLETE ME ***
    wake_up_process(thread);
    if (thread)
    {
        printk(KERN_INFO "Thread started\n");
    }
    else 
    {
        printk(KERN_INFO "Cannot create thread\n");
        return 1;
    }
    return 0;
}

static void __exit exit_mod(void)
{
    // Stop the thread
    // *** COMPLETE ME ***
    kthread_stop(thread);

    printk(KERN_INFO "Exiting!\n");
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