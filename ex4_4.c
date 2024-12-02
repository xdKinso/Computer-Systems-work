#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Create mutex
// *** COMPLETE ME ***
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void critical_section()
{
    // Get thread ID
    // *** COMPLETE ME ***
    pthread_t tid = pthread_self();
    // Print status
    printf("%lu entering mutex\n", tid);
    // Lock the mutex
    // *** COMPLETE ME ***
    pthread_mutex_lock(&mutex);
    // Print status
    printf("%lu in the mutex\n", tid);
    // Wait up to 4 seconds
    int wait = rand() % 5;
    printf("%lu waiting %d seconds\n", tid, wait);
    // Sleep wait seconds
    // *** COMPLETE ME ***
    sleep(wait);
    // Print status
    printf("%lu exiting mutex\n", tid);
    // Unlock the mutex
    // *** COMPLETE ME ***
    pthread_mutex_unlock(&mutex);
}

void* worker()
{
    // Enter critical section 10 times
    for (int i = 0; i < 10; ++i)
    {
        critical_section();
    }
    // Exit the thread
    // *** COMPLETE ME ***
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;
    // Create the threads
    // *** COMPLETE ME ***
    pthread_create(&t1, NULL,worker, NULL);
    // *** COMPLETE ME ***
    pthread_create(&t2, NULL,worker, NULL);

    // Join the threads
    void *status;
    // *** COMPLETE ME ***
    pthread_join(t1,&status);
    // *** COMPLETE ME ***
    pthread_join(t2,&status);
    // Destroy the mutex
    // *** COMPLETE ME ***
    pthread_mutex_destroy(&mutex);
    return 0;
}