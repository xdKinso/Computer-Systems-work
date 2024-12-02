#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void* handle_connection(void *arg)
{
    int socket_desc = (int)arg;
    int read_size;
    char buffer[2000];
    char message[2000];

    memset(buffer, 0, 2000);
    // Use recv to receive a message from the client
    read_size = recv(socket_desc, buffer, 2000, 0);

    while (read_size > 0)
    {
        // Check if the message is "quit"
        if (strcmp(buffer, "quit") == 0)
        {
            printf("Received quit command. Exiting connection handler...\n");
            break;
        }
        // Check if the message is "hello"
        else if (strcmp(buffer, "hello") == 0)
        {
            // Send "hello world" message back to the client
            printf("hello world");
        }
        else
        {
            printf("Received: %s\n", buffer);
            memset(message, 0, 2000);
            printf("Enter reply: ");
            fgets(message, sizeof(message), stdin);
            // Send message back to the client
            send(socket_desc, message, strlen(message), 0);
        }

        memset(buffer, 0, 2000);
        // Use recv to receive a message from the client
        read_size = recv(socket_desc, buffer, 2000, 0);
    }

    // Close the new connection
    close(socket_desc);

    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    int socket_desc;
    struct sockaddr_in server;
    int status;
    int port = 5000;
    int new_socket;
    struct sockaddr_in client;
    int size;
    pthread_t handler_thread[10];
    int handler_count = 0;
    int i;
    void *retval;

    // Create a socket
    socket_desc = socket(AF_INET,SOCK_STREAM,0);

    if (socket_desc == -1)
    {
        printf("Could not create socket\n");
        return -1;
    }

    // Set the family, address and port of the socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port); // Bind the socket
   // Bind the socket
    status = bind(socket_desc,(struct sockaddr*)&server,sizeof(server));

    if (status < 0)
    {
        printf("Failed to create server socket\n");
        return -1;
    }
    printf("Server socket created\n");

    // Listen on the server socket
    listen(socket_desc,3);

    printf("Server listening on port %d\n", port);

    size = sizeof(client);
    // Accept a new connection
    new_socket = accept(socket_desc,(struct sockaddr*)&client,&size);

    while (new_socket >= 0 && handler_count < 10)
    {
        printf("Connection successful\n");

        printf("Starting new connection handler\n");

        // Create a new thread using the handle_connection function. Pass the new_socket as a parameter.
        pthread_create(&handler_thread[i], NULL, handle_connection, (void*)new_socket);

        // Accept a new connection
        new_socket = accept(socket_desc,(struct sockaddr*)&client,&size);
    }

    printf("Shutting down server\n");

    for (i = 0; i < handler_count; ++i)
    {
        // Join thread i
        pthread_join(handler_thread[i], (void**)&status);
    }

    printf("Exiting...\n");

    // Close the server socket
    close(socket_desc);

    return 0;
}