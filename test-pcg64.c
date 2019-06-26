/*
 * PCG64 Random Number Generation for C.
 *
 * Copyright 2015 Robert Kern <robert.kern@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 *     http://www.pcg-random.org
 */

#include <stdio.h>

#include "pcg64.h"


void print_uint64_hex(uint64_t x)
{
    printf("%08x %08x\n", (unsigned int)(x >> 32u), (unsigned int)(x & 0xFFFFFFFFu));
}


int main(int argc, char** argv)
{
    pcg64_random_t rng;
    pcg64_srandom_r(&rng, PCG_128BIT_CONSTANT(0ULL, 42ULL),
	    PCG_128BIT_CONSTANT(0, 0x8000000000000054ULL));
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
