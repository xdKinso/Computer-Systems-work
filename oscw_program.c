#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define HELLO _IO('x', 0)
#define GOODBYE _IO('x', 1)
#define PRINT_1 _IO('x', 2)
#define PRINT_2 _IO('x', 3)
#define MY_WRITE _IOW('x', 4, unsigned long)
#define MY_READ _IOR('x',5, char*)
#define CLOSE _IO('x',6)
int main(int argc, char **argv)
{
    int fd;
    char *str[80];
    char input[80];
    printf("please enter the message to send with MY_WRITE:");
    fgets(input, sizeof(input), stdin);

    fd = open("/dev/my_device", O_RDWR);
    if (fd < 0) {
        printf("Failed to open device file\n");
        return 1;
    }
    while (1)
    {
        int choice;
        printf(" 1)run HELLO\n 2)GOODBYE\n 3)PRINT 1\n 4)PRINT 2\n 5)MY_READ\n 6)MY_WRITE\n0 to end program\n");
        printf("what would you like to do:");
        scanf("%d",&choice);
        if (choice == 1)
        {
            printf("running HELLO\n");
            ioctl(fd, HELLO);
        }
        else if (choice == 2)
        {
            printf("running GOODBYE\n");
            ioctl(fd, GOODBYE);
        }
        else if  (choice == 3)
        {
            printf("running print 1\n");
            ioctl(fd,PRINT_1);
        }
        else if (choice == 4)
        {
            printf("running print 2\n");
            ioctl(fd,PRINT_2);
        }
        else if (choice == 5)
        {
            printf("running MY_READ\n");
            char str[80];
            ioctl(fd,MY_READ,str);
            printf("My Module: %s \n", str);

        }
        else if (choice == 6)
        {
            ioctl(fd, MY_WRITE, input);

        }
        else if (choice ==  0)
        {
            printf("thankyou for using the program\n");     
            break;
        }
        else
        {
            printf("please enter a valid option\n");
        }
    }
    close(fd);
    return 0;
}
