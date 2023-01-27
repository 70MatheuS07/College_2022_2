#include <stdlib.h>
#include <stdio.h>
#include "bitmap.h"

#define TAM_CHAR 8

long long unsigned int binary_to_int(unsigned char *binary);

int main(int argc, char *argv[])
{
    unsigned char *longLongInt = malloc(sizeof(unsigned char) * TAM_CHAR);

    FILE *arquivo = fopen(argv[1], "rb");

    fread(longLongInt, sizeof(unsigned char), TAM_CHAR, arquivo);

    long long unsigned int num = binary_to_int(longLongInt);

    printf("%llu\n", num);

    return 0;
}

long long unsigned int binary_to_int(unsigned char *binary)
{
    int i;
    unsigned long long int n = 0;

    for (i = 0; i < 64; i++)
    {
        if (binary[i] == '1')
        {
            n |= (1LL << (63 - i));
        }
    }

    return n;
}