// C Program to multiply two matrix using pthreads without
// use of global variables
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 3

//Each thread computes single element in the resultant matrix
void *mult(void* arg)
{
    int *data = (int *)arg;
    int k = 0, i = 0;
    
    int x = data[0]; // x = c1 (number of elements to multiply)
    for (i = 1; i <= x; i++)
        k += data[i] * data[i+x];
    
    int *p = (int*)malloc(sizeof(int));
    *p = k;
    
    free(arg); // Free the argument data now that we're done with it
    pthread_exit(p);
}

//Driver code
int main()
{
    int matA[MAX][MAX];
    int matB[MAX][MAX];
    
    int r1=MAX, c1=MAX, r2=MAX, c2=MAX, i, j, k;

    // Generating random values in matA
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            matA[i][j] = rand() % 10;
    
    // Generating random values in matB
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            matB[i][j] = rand() % 10;
    
    // Displaying matA 
    printf("Displaying matA\n");
    for (i = 0; i < r1; i++){
        for(j = 0; j < c1; j++)
            printf("%d ",matA[i][j]);
        printf("\n");
    }
    
    printf("\n\n");
    
    // Displaying matB 
    printf("Displaying matB\n");
    for (i = 0; i < r2; i++){
        for(j = 0; j < c2; j++)
            printf("%d ",matB[i][j]);
        printf("\n");
    }
    
    printf("\n\n");
    
    int max = r1 * c2;
    
    // declaring array of threads of size r1*c2
    pthread_t *threads;
    threads = (pthread_t*)malloc(max * sizeof(pthread_t));
    
    int count = 0;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            // Allocate memory for this thread's arguments
            int *data = (int *)malloc((1 + c1 + r2) * sizeof(int));
            data[0] = c1; // Store the number of elements to multiply
            
            // Store row from matA
            for (k = 0; k < c1; k++)
                data[k+1] = matA[i][k];
            
            // Store column from matB
            for (k = 0; k < r2; k++)
                data[k+c1+1] = matB[k][j];
            
            // Create thread with unique data pointer
            pthread_create(&threads[count], NULL, mult, (void*)data);
            count++;
        }
    }
    
    printf("RESULTANT MATRIX IS :- \n");
    for (i = 0; i < max; i++) {
        void *result;
        // Joining all threads and collecting return value
        pthread_join(threads[i], &result);
        
        int *p = (int *)result;
        printf("%d ", *p);
        free(result); // Free the result memory after printing
        
        if ((i + 1) % c2 == 0)
            printf("\n");
    }
    
    free(threads); // Free the thread array
    
    return 0;
}