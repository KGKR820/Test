#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> // Added for exit()
#include <sys/wait.h> // Added for wait()

int this_is_global;

// Corrected function signature: must return void* and take a void* parameter
void *thread_func(void *ptr);

int main()
{
    int local_main;
    int pid, status;
    pthread_t thread1, thread2;

    printf("First, we create two threads to see better what context they share...\n");
    this_is_global = 1000;
    printf("Set this_is_global=%d\n", this_is_global);

    // Removed incorrect casts: thread_func already has correct signature
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("After threads, this_is_global=%d\n", this_is_global);
    printf("\n");
    printf("Now that the threads are done, let's call fork..\n");
    local_main = 17;
    this_is_global = 17;

    printf("Before fork(), local_main=%d, this_is_global=%d\n", local_main, this_is_global);

    pid = fork();
    if (pid == 0)
    {
        /* this is the child */
        // Use %p for pointers and cast to void*
        printf("In child, pid %d: &global: %p, &local: %p\n", getpid(),
               (void *)&this_is_global, (void *)&local_main);

        local_main = 13;
        this_is_global = 23;

        printf("Child set local main=%d, this_is_global=%d\n", local_main, this_is_global);
        exit(0);
    }
    else
    {
        /* this is parent */
        // Use %p for pointers and cast to void*
        printf("In parent, pid %d: &global: %p, &local: %p\n", getpid(),
               (void *)&this_is_global, (void *)&local_main);
        wait(&status);
        printf("In parent, local_main=%d, this_is_global=%d\n", local_main, this_is_global);
    }

    exit(0);
}

// Corrected function signature and implementation
void *thread_func(void *dummy)
{
    int local_thread;
    // Use %lu for pthread_t (long unsigned) and %p for pointers
    printf("Thread %lu, pid %d, addresses: &global: %p, &local: %p\n",
           (unsigned long)pthread_self(), getpid(),
           (void *)&this_is_global, (void *)&local_thread);

    this_is_global++;
    printf("In Thread %lu, incremented this_is_global=%d\n",
           (unsigned long)pthread_self(), this_is_global);
    pthread_exit(0);
    return NULL; // Good practice to return something
}