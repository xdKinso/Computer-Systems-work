#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

static int int_param = 0;
// Declare int_param as a module parameter of type int
// *** COMPLETE ME ***
module_param(int_param, int, 0);
// Set int_param description to "An integer"
// *** COMPLETE ME *** 
MODULE_PARM_DESC(int_param, "An integer");
static char *string_param = "Empty";
// Declare string_param as a module parameter of type charp
// *** COMPLETE ME ***
module_param(string_param, charp, 0);
// Set string_param description to "A string"
// *** COMPLETE ME ***
MODULE_PARM_DESC(string_param, "A string");

static int __init init_mod(void)
{
    printk(KERN_INFO "Hello, world!\n");
    // Print "int_param=<int_param>"
    // *** COMPLETE ME ***
    printk(KERN_INFO "int_param = %d\n", int_param);
    // Print "string_param=<string_param>"
    // *** COMPLETE ME ***
    printk(KERN_INFO "string_param = %s\n", string_param);
    return 0;
}

static void __exit exit_mod(void)
{
    printk(KERN_INFO "Goodbye, world!\n");
}

// Set hello_init as module initialisation
// *** COMPLETE ME ***
module_init(init_mod);
// Set hello_exit as module exit
// *** COMPLETE ME ***
module_exit(exit_mod);
// Set module license to GPL
// *** COMPLETE ME ***
MODULE_LICENSE("GPL");
// Set module author to your name and email
// *** COMPLETE ME ***
MODULE_AUTHOR("Krystian Mowinski  <Mowinskk@gmail.com>");
// Set module description to "A simple module"
// *** COMPLETE ME ***
MODULE_DESCRIPTION("A simple module");