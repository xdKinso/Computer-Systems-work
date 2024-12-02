#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Thread function
void* do_work()
{
    printf("I'm a thread!\n");
    // Exit the thread
    // *** COMPLETE ME ***
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t thread;
    // Create a thread using the do_work function
    // *** COMPLETE ME ***
    pthread_create(&thread,NULL,do_work,NULL);
    printf("I'm the main program!\n");
    
    void *status;
    // Join the thread
    // *** COMPLETE ME ***
    pthread_join(thread, &status);
    return 0;
}