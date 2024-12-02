#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* sleeper(void *arg)
{
    // Cast the argument to the right type
    int duration = (int)arg;
    // Get the current thread
    // *** COMPLETE ME ***
    pthread_t tid = pthread_self();
    // Wake up every duration
    for (int i = 0; i < 10; ++i)
    {
        printf("%lu awake!\n", tid);
        printf("%lu going to sleep\n", tid);
        // Sleep for duration seconds
        // *** COMPLETE ME ***
        sleep(duration);
    }
    // Exit the thread
    // *** COMPLETE ME ***
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;
    // Create thread 1 - sleeps 2 seconds
    // *** COMPLETE ME ***
    pthread_create(&t1, NULL, sleeper, (void*)2);
    // Create thread 2 - sleeps 3 seconds
    // *** COMPLETE ME ***
    pthread_create(&t2, NULL, sleeper, (void*)3);

    // Join the threads
    void *status;
    // Join thread 1
    // *** COMPLETE ME ***
    pthread_join(t1,&status);
    // Join thread 2
    // *** COMPLETE ME ***
    pthread_join(t2,&status);
    return 0;
}