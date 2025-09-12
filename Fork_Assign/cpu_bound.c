
int main() {
    while(1) {
        // CPU intensive calculation
        volatile int i;
        for(i = 0; i < 1000000; i++);
    }
    return 0;
}