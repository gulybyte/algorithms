#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long* linearCongruentialGenerator(long seed, long a, long c, long m, long n);

int main() {
    long seed = time(NULL);
    long m = 4294967296;
    long a = 1664525;
    long c = 1013904223;
    long n = 10;

    printf("\nseed: %d\n\n", seed);

    long* resultsLCG = linearCongruentialGenerator(seed, a, c, m, n);

    for (size_t i = 0; i < n; ++i) {
        printf("%ld ", resultsLCG[i]);
    }

    free(resultsLCG);
    return 0;
}

long* linearCongruentialGenerator(long x0, long a, long c, long m, long n) {
        
    long* results = (long*)malloc(n * sizeof(long));

    if(a > 0 && m > 0 && c >= 0 && x0 >= 0 && a < m && c < m && x0 < m) {
        for (long i = 0; i < n; ++i) {
            x0 = (a * x0 + c) % m;
            results[i] = x0;
        }
    } else {
        printf("Condições não satisfeitas");
        exit(EXIT_FAILURE);
    }

    return results;
}
