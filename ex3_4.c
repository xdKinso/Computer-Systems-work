#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Called when the parent exits
void parent_exit()
{
    // Print Exiting parent
    // *** COMPLETE ME ***
    printf("Exiting Parent\n");
    

}

// Called when the child exits
void child_exit()
{
    // Print Exiting child
    // *** COMPLETE ME ***
    printf("exiting child\n");
    
    

}

int main(int argc, char **argv)
{
    // Create new process
    // *** COMPLETE ME ***
    pid_t pid =fork();

    if (pid > 0)
    {
        // Set the appropriate exit function
        // *** COMPLETE ME ***
        atexit(parent_exit);
        // Exit the function in success
        // *** COMPLETE ME ***
        exit(EXIT_SUCCESS);
    }
    else if (!pid)
    {
        // Set the appropriate exit function
        // *** COMPLETE ME ***
        atexit(child_exit);
        // Exit the function in success
        // *** COMPLETE ME ***
        exit(EXIT_SUCCESS);
    }
    else if (pid == -1)
    {
        perror("fork");
    }
    return 0;
}