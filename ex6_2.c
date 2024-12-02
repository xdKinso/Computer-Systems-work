#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int num __initdata = 10;

static int __init hello_init(void)
{
    // Print "Hello, world!" as KERN_INFO
    // *** COMPLETE ME ***
    printk(KERN_INFO "Hello ,World! \n");
    // Print "Data is <num>" as KERN_INFO
    // *** COMPLETE ME ***
    printk(KERN_INFO "Data is ,%d\n", num);
    return 0;
}

static void __exit hello_exit(void)
{
    // Print "Goodbye, world!" as KERN_INFO
    // *** COMPLETE ME ***
    printk(KERN_INFO "Goodbye, World!\n");
}

MODULE_LICENSE("GPL");

// Set hello_init as module initialisation
// *** COMPLETE ME ***
module_init(hello_init);
// Set hello_exit as module exit
// *** COMPLETE ME ***
module_exit(hello_exit);
