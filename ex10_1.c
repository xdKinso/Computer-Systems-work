#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char **argv)
{
    // Create the socket
    // *** COMPLETE ME ***
    int socket_desc = socket(AF_INET,SOCK_STREAM,0);

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
    }
    else
    {
        printf("Socket created\n");
    }
    return 0;
}