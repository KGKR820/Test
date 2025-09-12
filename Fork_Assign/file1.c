#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <x> <n>\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        
        execl("./file2", "file2", argv[1], argv[2], NULL);
        perror("execl failed"); 
        exit(1);
    }
    else {
    
        wait(NULL);
        printf("Parent(PID=%d) : Done\n", getpid());
    }

    return 0;
}
