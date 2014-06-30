#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//the maximum size of prime seeds sqrt(1000000000) ~ 31622.xxx
#define MAX_SEEDS 31623
#define MAX_SEGMENT 100000

unsigned long seeds[MAX_SEEDS];
long seedCount = 0;
unsigned long pMax = 0;
short primes[MAX_SEGMENT];

void initSeeds(unsigned long max) {
    unsigned long i, j, bound, prevBound;
    short *sa;

    bound = (unsigned long)ceil(sqrt(max));
    prevBound = (unsigned long)ceil(sqrt(pMax));
    if(pMax < max) {
        sa = (short*)malloc((bound-prevBound)*sizeof(short));
        memset((void *)sa, 1, (bound-prevBound)*sizeof(short));

        for(i = 0; i < seedCount; i++) {
            for(j = prevBound + seeds[i]*seeds[i]; j <= bound; j+= seeds[i]) {
                sa[j-1-prevBound] = 0;
            }
        }

        i = prevBound <= 2 ? 2 : prevBound/2;

        for(; i <= bound ; i++) {
            if(sa[i-1-prevBound]) {
                seeds[seedCount++] = i;
                for(j = prevBound + i*i;j <= bound; j+=i) {
                    sa[j-1-prevBound] = 0;
                }
            }
        }

        free(sa);
        pMax = max;
    }

    return 0;
}

int main(void) {
    unsigned long i, m, n, upper, lower, p;
    int tests;

    scanf("%d", &tests);

    while(tests--) {
        scanf("%ld %ld", &m, &n);
        initSeeds(n);

        memset((void *)primes, 1, (n-m+1)*sizeof(short));

        for(i = 0, p=seeds[i]; i < seedCount && p*p <= n; i++, p = seeds[i]) {
            //start at the closest smaller number divisible by the prime on the lower bound and
            //end the the closest smaller number divisible by the prime on the upper bound
            upper = (n/p) * p;
            lower = (m/p)*p;
            lower = lower < m ? (lower + p == p ? (lower + p + p) : (lower + p)) : (lower == p ? lower + p : lower);
            for(; lower <= upper; lower += p) {
                if(lower >= m && lower <= n) {
                    primes[lower-m] = 0;
                }
            }
        }

        if(m == 1) primes[0] = 0;

        for(i = m; i <= n; i++) {
            if(primes[i-m]) {
                printf("%ld\n", i);
            }
        }
        printf("\n");
    }
}

