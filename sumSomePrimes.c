#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// answer is 49122557320

#define STA 49999951
#define END 50000000

#define N 1000000000

static bool primes[N + 1];

void sieve() {
    long long i, j, cnt = 0, sum = 0;

    for (i = 2; i <= N; i++)
        if (primes[i]) {
            cnt++;

            if (cnt >= STA && cnt <= END)
                sum += i;

            for (j = i * i; j <= N; j += i)
                primes[j] = false;
        }
    
    printf("Primes count is %lld\n", cnt);
    printf("Sum is %lld\n", sum);
}

int main() {
    memset(primes, true, N);
    sieve();

    return 0;
}
