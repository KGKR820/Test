#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process PID: %d\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process PID: %d\n", getpid());
        wait(NULL); // Wait for child to terminate
        printf("Child process %d terminated\n", pid);
    }
    
    return 0;
}