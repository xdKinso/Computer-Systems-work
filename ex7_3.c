#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/mutex.h>

// We have two threads and a mutex
static struct task_struct *thr1;
static struct task_struct *thr2;
static struct mutex mut;

int thread_function(void *args)
{
    int id = (int)args;
    // Loop until should stop
    // *** COMPLETE ME ***
    while (!kthread_should_stop())
    {
        // Lock the mutex
        // *** COMPLETE ME ***
        mutex_lock(&mut);
        printk(KERN_INFO "Thread %d in the critical section\n", id);
        printk(KERN_INFO "Thread %d waiting %d seconds\n", id, id);
        // Sleep for 1000 * id milliseconds
        // *** COMPLETE ME ***
        msleep(1000);
        printk(KERN_INFO "Thread %d exiting critical section\n", id);
        // Unlock the mutex
        // *** COMPLETE ME ***
        mutex_unlock(&mut);
    }
    return 0;
}

static int __init init_mod(void)
{
    // Initialise the mutex
    // *** COMPLETE ME ***
    mutex_init(&mut);
    // Create thr1 -- pass 1 as an argument (cast to void*)
    // *** COMPLETE ME ***
    thr1 = kthread_run(thread_function, 1,"Module Thread");
    // Create thr2 -- pass 2 as an argument (cast to void*)
    // *** COMPLETE ME ***
    thr2 = kthread_run(thread_function, 2,"Module Thread");

    if (thr1 && thr2)
    {
        printk(KERN_INFO "Threads started\n");
    }
    else 
    {
        printk(KERN_INFO "Cannot create threads\n");
        return 1;
    }
    return 0;
}

static void __exit exit_mod(void)
{
    // Stop thr1
    // *** COMPLETE ME ***
    kthread_stop(thr1);
    // Stop thr2
    // *** COMPLETE ME ***
    kthread_stop(thr2);

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