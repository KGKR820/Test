#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    FILE *fp;
    char line[100];
    pid_t pid;
    for(int i=0;i<4;i++){
        pid = fork();
        fp = fopen("./myfile.txt","r");
        int curr = 0;
        if(pid == 0){
            while(fgets(line,sizeof(line),fp)){
                if(curr == i){
                    printf("Child %d (PID %d): %s", i, getpid(), line);
                    break;
                }
                curr++;
            }
            fclose(fp);
            exit(0); 
        }
    }

    for (int i = 1; i <= 4; i++) {
        wait(NULL);
    }

    printf("Parent process (PID %d): All children finished.\n", getpid());
    return 0;
}