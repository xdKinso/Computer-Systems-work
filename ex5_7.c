#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <sched.h>
#include <unistd.h>

// The number of threads to launch
const int NUM_THREADS = 10;

// This function finds all the primes under 1000000
void find_primes(int tid)
{
    int max = 1000000;
    int count = 0;
    // Loop through all numbers up to 1000000
    for (int i = 2; i <= max; ++i)
    {
        // Flag to show if prime
        int prime = 1;
        // Loop through all numbers less than sqrt(i)
        for (int j = 2; j <= (int)sqrt(i); ++j)
        {
            // Test if prime
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }
        // If prime, increment counter
        if (prime)
        {
            ++count;
        }
    }
    // Print out how many primes found
    printf("Thread %d found %d primes\n", tid, count);
}

// The function run by a thread
void* do_work(void *args)
{
    int id = (int)args;
    printf("%d working\n", id);
    find_primes(id);
    return 0;
}

int main(int argc, char **argv)
{
    // Get the current process
    pid_t pid = getpid();
    // Create data on the CPUs we want to run on 
    cpu_set_t set;
    // Zero the data
    // *** COMPLETE ME ***
    CPU_ZERO(&set);
    // Select CPU 0
    // *** COMPLETE ME ***
    CPU_SET(0,&set);
    // Set process affinity
    // *** COMPLETE ME ***
    sched_setaffinity(pid,sizeof(cpu_set_t),&set);
    // Create sched_param
    struct sched_param param;
    // Set priority to maximum (20)
    param.sched_priority = 20;
    // Set scheduler to FIFO queue
    // *** COMPLETE ME ***
    sched_setscheduler(pid,SCHED_FIFO,&param);
    // Run NUM_THREADS
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_attr_t attr;
        // Initialise the attr
        // *** COMPLETE ME ***
        pthread_attr_init(&attr);
        // Set we are using an explicit scheduler
        // *** COMPLETE ME ***
        pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
        // Set that we are using SCHED_RR
        // *** COMPLETE ME ***

        pthread_attr_setschedpolicy(&attr, SCHED_RR);
        struct sched_param param;
        // Set the priority in param to i % 3 + 1
        // (i.e., we use priorities 1-4 only)
        // *** COMPLETE ME ***
        param.sched_priority = i % 3 + 1;
        // Attach the param to the attr
        // *** COMPLETE ME ***
        pthread_attr_setschedparam(&attr, &param);
        // Create the thread - remember to point to the attr
        // *** COMPLETE ME ***
        pthread_create(&threads[i],&attr, do_work,(void*)i);
    }
    void *status;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // Join the thread
        // *** COMPLETE ME ***
        pthread_join(threads[i],&status);
    }
    return 0;
}