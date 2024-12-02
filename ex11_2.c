#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int socket_desc;
    struct sockaddr_in server;
    int status;
    int port = 5000;
    int new_socket;
    struct sockaddr_in client;
    int size;

    // Create a socket
    // *** COMPLETE ME ***
    socket_desc = socket(AF_INET,SOCK_STREAM,0);

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
        return -1;
    }

    // Set the family, address and port of the socket
    // *** COMPLETE ME ***
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    // Bind the socket
    // *** COMPLETE ME ***
    status = bind(socket_desc,(struct sockaddr*)&server,sizeof(server));


    if (status < 0)
    {
        printf("Failed to create server socket\n");
        return -1;
    }
    printf("Server socket created\n");

    // Listen on the server socket
    // *** COMPLETE ME ***
    listen(socket_desc,3);

    printf("Server listening on port %d\n", port);

    size = sizeof(client);
    // Accept a new connection
    // *** COMPLETE ME ***
    new_socket = accept(socket_desc,(struct sockaddr*)&client,&size);

    if (new_socket < 0)
    {
        printf("Error accepting incoming connection\n");
        return -1;
    }

    printf("Connection successful\n");

    // Close the new connection
    // *** COMPLETE ME ***
    close(new_socket);
    // Close the server socket
    // *** COMPLETE ME ***
    close(socket_desc);

    return 0;
}