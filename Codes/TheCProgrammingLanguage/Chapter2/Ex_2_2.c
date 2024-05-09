#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("Ranges of char:\n");
    printf("Signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 to %u\n", UCHAR_MAX);

    printf("\nRanges of short:\n");
    printf("Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 to %u\n", USHRT_MAX);

    printf("\nRanges of int:\n");
    printf("Signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0 to %u\n", UINT_MAX);

    printf("\nRanges of long:\n");
    printf("Signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("\nRanges of floating-point types:\n");
    printf("Float: %E to %E\n", FLT_MIN, FLT_MAX);
    printf("Double: %E to %E\n", DBL_MIN, DBL_MAX);
    printf("Long double: %LE to %LE\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
