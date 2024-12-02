#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

// Our character device
static struct miscdevice my_dev;

static int __init init_function(void)
{
    int result;
    // Set minor of device to MISC_DYNAMIC_MINOR
    // *** COMPLETE ME ***
    my_dev.minor = MISC_DYNAMIC_MINOR;
    // Give the device the name my_device
    // *** COMPLETE ME ***
    my_dev.name = "my_device";
    // Set fops of device to NULL
    // *** COMPLETE ME ***
    my_dev.fops = NULL;
    // Register the device getting the result
    // *** COMPLETE ME ***
    result = misc_register(&my_dev);
    if (result) {
        printk(KERN_ERR "Creating device failed\n");
        return 0;
    }
    printk(KERN_INFO "Device %d created\n", my_dev.minor);
    return 0;
}

static void __exit exit_function(void)
{
    // Deregister the device
    // *** COMPLETE ME ***
    misc_deregister(&my_dev);
    printk(KERN_INFO "Device removed\n");
}

// Set module initialisation function
// *** COMPLETE ME ***
module_init(init_function);
// Set module exit function
// *** COMPLETE ME ***
module_exit(exit_function)
// Set module license to GPL
// *** COMPLETE ME ***
MODULE_LICENSE("GPL");
// Set module author
// *** COMPLETE ME ***
MODULE_AUTHOR("Krystian Mowinski  <Mowinskk@gmail.com>");
// Set module description
// *** COMPLETE ME ***
MODULE_DESCRIPTION("A simple module");