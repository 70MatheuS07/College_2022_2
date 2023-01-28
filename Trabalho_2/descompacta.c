#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bitmap.h"

#define TAM_CHAR 8

void TransformaInteiroBinarioDescompacta(int n, int *vet, int id);

long long unsigned int binary_to_int(unsigned char *binary);

int main(int argc, char *argv[])
{
    long long int tamanhoArquivoBits = 0;

    bitmap *mapaBits = bitmapInit(64);

    FILE *arquivo = fopen(argv[1], "rb");

    fread(&tamanhoArquivoBits, sizeof(long long int), 1, arquivo);

    printf("\n\n%lld\n\n", tamanhoArquivoBits);

    fclose(arquivo);

    printf("%0xh\n", bitmapGetContents(mapaBits)[0]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[1]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[2]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[3]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[4]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[5]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[6]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[7]);

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

void TransformaInteiroBinarioDescompacta(int n, int *vet, int id)
{
    if (n == 0)
    {
        vet[id] = n;
    }
    else
    {
        TransformaInteiroBinarioDescompacta(n / 2, vet, id - 1);
        vet[id] = n % 2;
    }
}