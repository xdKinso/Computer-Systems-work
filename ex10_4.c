#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    char *hostname = "www.roehampton.ac.uk";
    char ip[100];
    //struct hostent *he;
    //struct in_addr *addr;
    //int socket_desc;
    struct sockaddr_in server;
    int status;
    char *message;

    // Resolve the host name
    // *** COMPLETE ME ***
    struct hostent* he = gethostbyname("www.roehampton.ac.uk");

    if (he == NULL)
    {
        printf("Get hostname failed\n");
        return 1;
    }

    // Get first address and convert to in_addr type
    // *** COMPLETE ME ***
    struct in_addr *addr = (struct in_addr*)he->h_addr_list[0];
   
    // Copy the address into IP buffer using inet_ntoa
    // *** COMPLETE ME ***
    strcpy(ip,inet_ntoa(*addr));

    printf("%s resolved to: %s\n", hostname, ip);

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

    // Set the address of the sockaddr_in structure
    // *** COMPLETE ME ***
    server.sin_addr.s_addr = inet_addr(ip);

    // Set the protocol family of the sockaddr_in structure
    // *** COMPLETE ME ***
    server.sin_family = AF_INET;

    // Set the port of the sockaddr_in structure
    // *** COMPLETE ME ***
    server.sin_port = htons(80);

    // Connect to the web server
    // *** COMPLETE ME ***
    status = connect(socket_desc,(struct sockaddr*)&server,sizeof(server));

    if (status < 0)
    {
        printf("Connection error\n");
        return 1;
    }
    
    printf("Connected\n");

    // Construct message
    // *** COMPLETE ME ***
    message = "GET / HTTP/1.1\r\n\r\n";
    // Send message
    // *** COMPLETE ME ***
    status = send(socket_desc,message,strlen(message), 0);

    if (status < 0)
    {
        printf("Send failed");
        return 1;
    }

    printf("Data sent\n");

    return 0;
}