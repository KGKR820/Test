#include <stdio.h>
#include <unistd.h>

int main() {
    int var = 42;
    printf("Process PID: %d, Variable address: %p\n", getpid(), &var);
    
    while(1) {
        // Long loop
        sleep(1);
    }
    
    return 0;
}