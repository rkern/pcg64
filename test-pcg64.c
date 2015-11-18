#include <stdio.h>

#include "pcg64.h"


void print_uint64_hex(uint64_t x)
{
    printf("%08x %08x\n", (unsigned int)(x >> 32u), (unsigned int)(x & 0xFFFFFFFFu));
}


int main(int argc, char** argv)
{
    pcg64_random_t rng;
    pcg64_srandom_r(&rng, PCG_128BIT_CONSTANT(0ULL, 42ULL), PCG_128BIT_CONSTANT(0ULL, 54ULL));
    for (int i=0; i < 100; i++) {
        print_uint64_hex(pcg64_random_r(&rng));
    }
#ifdef PCG_EMULATED_128BIT_MATH
    printf("Using emulated 128-bit math.\n");
#else
    printf("Using native 128-bit math.\n");
#endif
    return 0;
}
