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

    return 0;
}