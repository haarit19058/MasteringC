#include <stdio.h>
#include <stdint.h>

#define MT19937_N 624
#define MT19937_M 397
#define MT19937_MATRIX_A 0x9908b0dfUL
#define MT19937_UPPER_MASK 0x80000000UL
#define MT19937_LOWER_MASK 0x7fffffffUL
#define MT19937_TEMPERING_MASK_B 0x9d2c5680UL
#define MT19937_TEMPERING_MASK_C 0xefc60000UL
#define MT19937_TEMPERING_SHIFT_U(y) (y >> 11)
#define MT19937_TEMPERING_SHIFT_S(y) (y << 7)
#define MT19937_TEMPERING_SHIFT_T(y) (y << 15)
#define MT19937_TEMPERING_SHIFT_L(y) (y >> 18)

static uint32_t mt[MT19937_N];
static int mti = MT19937_N + 1;

void init_genrand(uint32_t s) {
    mt[0] = s & 0xffffffffUL;
    for (mti = 1; mti < MT19937_N; mti++) {
        mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
        mt[mti] &= 0xffffffffUL;
    }
}

uint32_t genrand_int32() {
    uint32_t y;
    static uint32_t mag01[2] = {0x0UL, MT19937_MATRIX_A};

    if (mti >= MT19937_N) {
        int kk;
        if (mti == MT19937_N + 1) init_genrand(5489UL);
        for (kk = 0; kk < MT19937_N - MT19937_M; kk++) {
            y = (mt[kk] & MT19937_UPPER_MASK) | (mt[kk + 1] & MT19937_LOWER_MASK);
            mt[kk] = mt[kk + MT19937_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (; kk < MT19937_N - 1; kk++) {
            y = (mt[kk] & MT19937_UPPER_MASK) | (mt[kk + 1] & MT19937_LOWER_MASK);
            mt[kk] = mt[kk + (MT19937_M - MT19937_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[MT19937_N - 1] & MT19937_UPPER_MASK) | (mt[0] & MT19937_LOWER_MASK);
        mt[MT19937_N - 1] = mt[MT19937_M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];
        mti = 0;
    }
    y = mt[mti++];
    y ^= MT19937_TEMPERING_SHIFT_U(y);
    y ^= MT19937_TEMPERING_SHIFT_S(y) & MT19937_TEMPERING_MASK_B;
    y ^= MT19937_TEMPERING_SHIFT_T(y) & MT19937_TEMPERING_MASK_C;
    y ^= MT19937_TEMPERING_SHIFT_L(y);
    return y;
}

int main() {
    init_genrand(5489UL); // Seed the generator
    printf("Random numbers:\n");
    for (int i = 0; i < 5; i++) {
        printf("%u\n", genrand_int32());
    }
    return 0;
}
