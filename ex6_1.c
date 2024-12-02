#include <linux/module.h>
#include <linux/kernel.h>

int init_module()
{
    // Print Hello, World! as KERN_INFO message
    // *** COMPLETE ME ***
    printk(KERN_INFO "Hello,world!\n");
    return 0;
}

void cleanup_module()
{
    // Print Goodbye, World! as KERN_INFO message
    // *** COMPLETE ME ***
    printk(KERN_INFO "Goodbye, world!\n");
}

MODULE_LICENSE("GPL");
