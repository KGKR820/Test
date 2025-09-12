#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {
        printf("I/O bound process running\n");
        sleep(1); // Simulate I/O wait
    }
    return 0;
}