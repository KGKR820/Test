#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i;
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        for (i = 0; i < 10; i++) {
            printf("Child: %d\n", i);
            // sleep(1); // Uncomment to make child finish before parent
        }
        exit(0);
    } else {
        // Wait for child to finish first
        wait(NULL);
        // Parent process
        for (i = 0; i < 10; i++) {
            printf("Parent: %d\n", i);
        }
    }
    
    return 0;
}