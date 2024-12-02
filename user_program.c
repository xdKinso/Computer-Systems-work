#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define MY_CALL _IO('x', 0)
#define MY_WRITE _IOW('x', 1, unsigned long)
#define MY_READ _IOR('x',2, char*)
int main(int argc, char **argv)
{
    int fd;
    char *str[80];
    // Open the device in O_RDWR mode
    // *** COMPLETE ME ***
    fd = open("/dev/my_device", O_RDWR);
    // Use ioctl to send MY_CALL message
    // *** COMPLETE ME ***
    ioctl(fd, MY_CALL);
    ioctl(fd, MY_WRITE, 54u);
    ioctl(fd, MY_READ, str);
    printf("Received %s from driver\n", str);
    // Close the device
    // *** COMPLETE ME ***
    close(fd);
    return 0;
}