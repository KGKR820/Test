#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <x> <n>\n", argv[0]);
        exit(1);
    }

    double x = atof(argv[1]);
    int n = atoi(argv[2]);

    if (n < 1) {
        fprintf(stderr, "Error: n must be >= 1\n");
        exit(1);
    }

    double sum = 1.0; // first term
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i) / factorial(i);
    }

    printf("Child(PID=%d) : e^%.2f (using %d terms) = %.6f\n", getpid(), x, n, sum);

    return 0;
}
