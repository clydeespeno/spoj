#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int tests;
    long pow5[] = {5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};

    scanf("%d", &tests);

    while(tests-- > 0) {
        long facNum;
        long zeros = 0;
        long p = 0;

        scanf("%ld", &facNum);

        while(p < 12 && pow5[p] <= facNum) {
            zeros += facNum/pow5[p++];
        }

        printf("%ld\n", zeros);
    }

    return 0;
}