#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
    // Print "Hello, world!" as KERN_INFO 
    // *** COMPLETE ME *** 
    printk(KERN_INFO "Hello, World!\n");
    return 0;
}

static void __exit hello_exit(void)
{
    // Print "Goodbye, world!" as KERN_INFO
    // *** COMPLETE ME ***
    printk(KERN_INFO "Goodbye, world!\n");
}

// Set hello_init as module initialisation
// *** COMPLETE ME ***
module_init(hello_init);
// Set hello_exit as module exit
// *** COMPLETE ME ***
module_exit(hello_exit);
// Set module license to GPL
// *** COMPLETE ME ***
MODULE_LICENSE("GPL");

// Set module author to your name and email
// *** COMPLETE ME ***
MODULE_AUTHOR("Krystian Mowinski  <Mowinskk@gmail.com>");

// Set module description to "A simple module"
// *** COMPLETE ME ***
MODULE_DESCRIPTION("A simple module");