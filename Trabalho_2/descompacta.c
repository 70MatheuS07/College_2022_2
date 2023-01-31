#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bitmap.h"
#include "Arvore.h"

void TransformaInteiroBinarioDescompacta(int n, int *vet, int id);

long long unsigned int binary_to_int(unsigned char *binary);

int main(int argc, char *argv[])
{
    unsigned long int tamanhoArquivoBits = 0;

    bitmap *mapaBits = bitmapInit(32);

    FILE *arquivo = fopen(argv[1], "rb");

    fread(&tamanhoArquivoBits, sizeof(unsigned long int), 1, arquivo);

    printf("\n\n%ld\n\n", tamanhoArquivoBits);

    int bytesArq = (int)tamanhoArquivoBits - 32;
    printf("\n\nbites: %d\n\n", bytesArq);

    ////////////////////////////
    bitmap *bm;

    if (bytesArq % TAM_CHAR == 0)
    {
        bm = bitmapInit(bytesArq);
    }
    else
    {
        bm = bitmapInit(((bytesArq / TAM_CHAR) + 1) * TAM_CHAR);
    }

    unsigned char byte;
    int vet[TAM_CHAR];

    printf("conteudo descompacta\n");
    // pegar de byte a byte
    for (int cont = 0; bytesArq > 0; cont++)
    {
        fread(&byte, sizeof(unsigned char), 1, arquivo);
        // zerar vetor para evitar erro na funçao trasformaInteiroBinario
        for (int i = 0; i < TAM_CHAR; i++)
        {
            vet[i] = 0;
        }

        // trasformar o byte em no binario pra passar pro bitmap
        TransformaInteiroBinario(byte, vet, TAM_CHAR - 1);

        for (int i = 0; i < TAM_CHAR; i++)
        {
            bitmapAppendLeastSignificantBit(bm, vet[i]);
        }

        printf("%0xh\n", bitmapGetContents(bm)[cont]);
        // printf("%d ", byte);
        bytesArq = bytesArq - TAM_CHAR;
    }

    fclose(arquivo);
    /*
    printf("\n%0xh\n", bitmapGetContents(mapaBits)[0]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[1]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[2]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[3]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[4]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[5]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[6]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[7]);

    printf("%0xh\n", bitmapGetContents(mapaBits)[8]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[9]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[10]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[11]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[12]);
    */

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