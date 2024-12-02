#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/ioctl.h>

#define HELLO _IO('x', 0)
#define GOODBYE _IO('x', 1)
#define PRINT_1 _IO('x', 2)
#define PRINT_2 _IO('x', 3)
#define MY_WRITE _IOW('x', 4, unsigned long)
#define MY_READ _IOR('x',5, char*)
#define CLOSE _IO('x',6)

static struct miscdevice my_dev;
int int1 = 0;
int int2 = 0;
module_param(int1, int, 0);
module_param(int2, int, 0);
MODULE_PARM_DESC(int1 ,"INTEGER 1");
MODULE_PARM_DESC(int2 ,"INTEGER 2");

static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);
static long device_ioctl(struct file*, unsigned int cmd, unsigned long);




//#define MY_WRITE _IOW('x',2, unsigned long)

//#define MY_READ _IOR('x',3,char*)

struct file_operations fops =
{
  
    .owner = THIS_MODULE,

    .open = device_open,

    .release = device_release,   
  
    .unlocked_ioctl = device_ioctl,

};

static int __init init_function(void)
{
    int result;
   
    my_dev.minor = MISC_DYNAMIC_MINOR;

    my_dev.name = "my_device";

    my_dev.fops = &fops;

    my_dev.mode = S_IALLUGO;  

    result = misc_register(&my_dev);

    if (result) {
        printk(KERN_ERR "Creating device failed\n");
        return 0;
    }
    //printk(KERN_INFO "Device %d created\n", my_dev.minor);
    return 0;
}

static void __exit exit_function(void)
{
    
    misc_deregister(&my_dev);
    printk(KERN_INFO "Device removed\n");
}

static int device_open(struct inode *inode, struct file *file)
{
    //printk(KERN_INFO "Device open function called\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    //printk(KERN_INFO "Device release function called\n");
    return 0;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    //char *msg = "Hello, world!";
    //int len = strlen(msg);
    switch (cmd)
    {
        case HELLO:
            printk(KERN_INFO "Hello World\n");
            //break
        case GOODBYE:
            printk(KERN_INFO "GOODBYE\n");
            //break;
        case PRINT_1:
            printk(KERN_INFO "the current number for int 1 is: %d",int1);
            int1 = int1 + 1;
            printk(KERN_INFO "when you add 1 it is : %d",int1);
            //printk(KERN_INFO "MY_WRITE recieved %lu\n",arg);
            //break;
        case PRINT_2:
            printk(KERN_INFO "the current number for int2 is : %d",int2);
            int2 = int2 + 1;
            printk(KERN_INFO "When you add 1 it is : %d",int2);
            //break;
        case MY_READ:
                //*msg
            char *msg = "int1:%d int2:%d",int1 , int2;
            int len = strlen(msg);
            printk(KERN_INFO "MY_READ recieved \n");
            copy_to_user((char*)arg, msg, len);
            //break;
        case MY_WRITE:
            printk(KERN_INFO "MY MODULE RECIEVED: %lu\n");
    }
    return 0;
}


module_init(init_function);

module_exit(exit_function);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Krystian Mowinski  <Mowinskk@gmail.com>");

MODULE_DESCRIPTION("A simple module");