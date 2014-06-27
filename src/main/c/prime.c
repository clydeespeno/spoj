#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long* generateSieve(long max, long *len);
void filterSieve(unsigned long* sieve, long first, long *len);

int main(void) {

    long len;
    long i = 0;

    unsigned long* sieve = generateSieve(100L, &len);

    printf("generated primes: %ld\n", len);

    for(;i < len; i++) {
        printf("%2ld ", sieve[i]);
        if((i+1)%5 == 0 && i != 0) printf("\n");
    }
}

unsigned long* generateSieve(long max, long *len) {

    unsigned long *initSieve;
    long k = lround(((double)(max)/6.0));
    long i;
    long km1;
    long kp1;

    *(initSieve++) = 2;
    *(initSieve++) = 3;

    *len = 2;

    for(i = 1, km1 = 6*i - 1, kp1 = 6*i + 1; i <= k && km1 <= max && kp1 <= max; i++, km1 = 6*i - 1, kp1 = 6*i + 1) {

        if(km1%2 != 0 && km1 %3 != 0) {
            *(initSieve++) = km1;
            *len += 1;
        }

        if(kp1%2 != 0 && kp1 %3 != 0) {
            *(initSieve++) = kp1;
            *len += 1;
        }
    }
    initSieve -= *len;

    filterSieve(initSieve, 3, len);

    return initSieve;
}

void filterSieve(unsigned long* sieve, long first, long *len) {

    if(first == *len) {
        return;
    }

    unsigned long curr = sieve[first];

    long idx = first+1;
    long copyIdx = first+1;

    long initLen = *len;

    while(idx < initLen) {
        if(sieve[idx]%curr == 0) {
            copyIdx = idx;
            *len--;
        } else {
            sieve[copyIdx] = sieve[idx];
        }
        idx++;
    }
}