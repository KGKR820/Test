#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
    void *kidfunc(void *p){
        printf("Kid Id is %d\n",getpid());
        return NULL;
    }
int main(){
    pthread_t kid;
    pthread_create(&kid,NULL,kidfunc,NULL);
    printf("Parent Id is %d\n",getpid());
    pthread_join(kid,NULL);
    printf("NO MORE CHILD");
}