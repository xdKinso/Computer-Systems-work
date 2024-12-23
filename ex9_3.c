#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/ioctl.h>

static struct miscdevice my_dev;

static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);
static long device_ioctl(struct file*, unsigned int cmd, unsigned long);

// Define the MY_CALL message
// *** COMPLETE ME ***
#define MY_CALL _IO('x',0)
// Define the MY_WRITE message
// *** COMPLETE ME ***
#define MY_WRITE _IOW('x',1, unsigned long)

struct file_operations fops =
{
    // Set device owner
    // *** COMPLETE ME ***
    .owner = THIS_MODULE,
    // Set open function
    // *** COMPLETE ME ***
    .open = device_open,
    // Set release function
    // *** COMPLETE ME ***
    .release = device_release,   
    // Set unlocked ioctl function
    // *** COMPLETE ME ***
    .unlocked_ioctl = device_ioctl,

};

static int __init init_function(void)
{
    int result;
    // Set minor of device to MISC_DYNAMIC_MINOR
    // *** COMPLETE ME ***
    my_dev.minor = MISC_DYNAMIC_MINOR;
    // Give the device the name my_device
    // *** COMPLETE ME ***
    my_dev.name = "my_device";
    // Set fops of device to fops
    // *** COMPLETE ME ***
    my_dev.fops = &fops;
    // Set mode to allow all permissions
    // *** COMPLETE ME ***
    my_dev.mode = S_IALLUGO;  
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

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device open function called\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device release function called\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch (cmd)
    {
        // Respond to MY_CALL message
        // *** COMPLETE ME ***
        case MY_CALL:
            printk(KERN_INFO "Recieved MY_CALL\n");
            break;
        // Respond to MY_WRITE message
        // *** COMPLETE ME ***
        case MY_WRITE:
            printk(KERN_INFO "MY_WRITE recieved %lu \n", arg);
            break;
    }
    return 0;
}

// Set module initialisation function
// *** COMPLETE ME ***
module_init(init_function);
// Set module exit function
// *** COMPLETE ME ***
module_exit(exit_function);
// Set module license to GPL
// *** COMPLETE ME ***
MODULE_LICENSE("GPL");
// Set module author
// *** COMPLETE ME ***
MODULE_AUTHOR("Krystian Mowinski  <Mowinskk@gmail.com>");
// Set module description
// *** COMPLETE ME ***
MODULE_DESCRIPTION("A simple module");
