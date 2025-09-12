#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> // Added for exit()

#define NUM_THREADS 5

void *PrintHello(void *threadid) 
{ 
    // FIX: Cast the void* argument back to an int before printing
    int tid = (int)(long)threadid; // First cast to long to avoid warning on 64-bit, then to int
    printf("%d: Hello World!\n", tid); 
    pthread_exit(NULL); 
}

int main( ) 
{ 
    pthread_t threads[NUM_THREADS]; 
    int rc, t;

    for(t = 0; t < NUM_THREADS; t++) 
    {
        printf("Creating thread %d\n", t); 
        // Pass the integer 't' by casting it to a void*
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)(long)t ); 
        if (rc) 
        { 
            printf("ERROR; return code from pthread_create() is %d\n", rc); 
            exit(-1); 
        } 
    } 

    // FIX: Wait for all threads to complete before main exits.
    // This is better than just pthread_exit in main.
    for(t = 0; t < NUM_THREADS; t++) 
    {
        pthread_join(threads[t], NULL);
    }

    printf("Main: All threads completed. Exiting.\n");
    // pthread_exit(NULL); // Not needed now as we join all threads.
    return 0;
}