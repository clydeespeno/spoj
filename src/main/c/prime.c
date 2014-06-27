#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long* generateSieve(long max, long *len);
void filterSieve(long* sieve, long first, long *len, long max);

int main(void) {

    long len;
    long i = 0;

    long* sieve = generateSieve(3865L, &len);

    printf("generated primes: %ld\n", len);

    for(;i < len; i++) {
        printf("%3ld ", sieve[i]);
        if((i+1)%10 == 0 && i != 0) printf("\n");
    }
}

long* generateSieve(long max, long *len) {

    long *initSieve;
    long k = lround(((double)(max)/6.0));
    long i;
    long km1;
    long kp1;

    *(initSieve++) = 2;
    *(initSieve++) = 3;

    *len = 2;

    for(i = 1, km1 = 6*i - 1, kp1 = 6*i + 1; i <= k; i++, km1 = 6*i - 1, kp1 = 6*i + 1) {

        if(km1%2 != 0 && km1 %3 != 0 && km1 <= max) {
            *(initSieve++) = km1;
            *len += 1;
        }

        if(kp1%2 != 0 && kp1 %3 != 0 && kp1 <= max) {
            *(initSieve++) = kp1;
            *len += 1;
        }
    }
    initSieve -= *len;
    printf("init length - %ld\n", *len);
    filterSieve(initSieve, 2, len, max);

    return initSieve;
}

void filterSieve(long* sieve, long first, long *len, long max) {

    long curr = *(sieve+first);

    if(curr > (long)sqrt(max)) {
        return;
    }

    long idx = first+1;
    long copyIdx = first+1;

    long initLen = *len;

    while(idx < initLen) {
        long idxed = *(sieve+idx);
        if(idxed%curr == 0) {
            *len -= 1;
        } else {
            *(sieve+copyIdx) = idxed;
            copyIdx++;
        }
        idx++;
    }

    filterSieve(sieve, first+1, len, max);
}