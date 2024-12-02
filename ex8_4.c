#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

static struct miscdevice my_dev;

static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);
static ssize_t device_read(struct file*, char __user*, size_t, loff_t*);
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);

struct file_operations fops =
{
    // Set owner of the module
    // *** COMPLETE ME ***
    .owner = THIS_MODULE,
    // Point to open function
    // *** COMPLETE ME ***
    .open = device_open,
    // Point to release function
    // *** COMPLETE ME ***
    .release = device_release,
    // Point to read function
    // *** COMPLETE ME ***
    .read = device_read,
    // Point to write function
    // *** COMPLETE ME ***
    .write = device_write,
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
    // Deregister device
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

static ssize_t device_read(struct file *file, char __user *buf, size_t len, loff_t *offset)
{
    size_t msg_len;
    int result = 0;
    char kernel_buffer[255];
    strcpy(kernel_buffer, "Hello, world!\n");
    msg_len = strlen(kernel_buffer);
    // Copy data to user memory, storing result
    // *** COMPLETE ME ***
    result = copy_to_user(buf, kernel_buffer, msg_len);
    if (result) {
        printk(KERN_ERR "Device read error\n");
    }
    printk(KERN_INFO "Device read function completed\n");
    return msg_len;
}

static ssize_t device_write(struct file *file, const char *buf, size_t len, loff_t *offset)
{
    printk(KERN_INFO "Device write function called\n");
    return len;
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
