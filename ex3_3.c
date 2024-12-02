#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Create a process using fork
    pid_t pid = fork();// *** COMPLETE ME ***
    if (pid > 0)
    {

       
       
        // Print numbers 0 to 10
        // e.g., "Parent 0"
        int i;
        for ( i = 0; i < 11; i++ ){
            printf("parent%d\n", i);
        }

        
    }
    else if (!pid)
    {
        // Print numbers 0 to 10
        // e.g., "=====>Child 0"
        // *** COMPLETE ME ***
        int i;
        for ( i = 0; i < 11; i++ ){
            printf("=====>Child  %d\n", i);
        } 
    }
    else if (pid == -1)
    {
        perror("fork");
    }
    return 0;
}