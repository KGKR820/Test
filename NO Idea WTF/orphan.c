#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    pid_t pid;
    printf("Original Process => pid : %d \n ppid : %d \n",getpid(),getppid());
    pid = fork();
    if(pid > 0){
        printf("Parent => pid : %d \n ppid : %d \n",getpid(),getppid());
        printf("My child's PID is %d\n", pid ) ;
    }
    else{
        sleep(4);
        printf("Child => pid : %d \n ppid : %d \n",getpid(),getppid());
        printf("My child's PID is %d\n", pid ) ;
    }
    printf ("PID %d terminates.\n", getpid()) ;
    return 0;
}