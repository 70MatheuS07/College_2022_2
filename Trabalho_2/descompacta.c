#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bitmap.h"
#include "VetorFreq.h"
#include "ListaArv.h"

#define TAM_CHAR 8

void CriaArquivoTxt(char *nomeArquivo, Arv *arvore, bitmap *mapaBits, int totalBitsTexto);

int main(int argc, char *argv[])
{
    unsigned long int tamanhoTextoBits = 0;

    FILE *arquivo = fopen(argv[1], "rb");

    fread(&tamanhoTextoBits, sizeof(unsigned long int), 1, arquivo);

    printf("\n\n%ld\n\n", tamanhoTextoBits);

    int vetor[NUM_ASCII];
    ZeraVetorFreq(vetor, NUM_ASCII);

    fread(vetor, sizeof(int), NUM_ASCII, arquivo);

    /////////////////////////////////////////
    ListaArv *lista = IniciaListaArv();

    PreencheListaArvFrequencia(lista, vetor, NUM_ASCII);

    ImprimeListaArv(lista);

    Arv *arvore = CriaArv_Vazia();
    arvore = ExecutaAlgoritimoDeHuffman(lista);

    printf("\n\n");
    Imprime(arvore);
    printf("\n\n");

    /////////////////////////////////////////
    bitmap *bm;

    int bytesArq = tamanhoTextoBits;
    printf("\n\nbites: %d\n\n", bytesArq);

    bm = bitmapInit(bytesArq);

    unsigned char byte;

    printf("conteudo descompacta\n");
    // pegar de byte a byte
    for (unsigned int cont = 0; bytesArq > 0; cont++)
    {
        fread(&byte, sizeof(unsigned char), 1, arquivo);
        
        bitmapSetContents(bm, &byte, cont);

        printf("%0xh\n", bitmapGetContents(bm)[cont]);
        // printf("%d ", byte);
        bytesArq = bytesArq - TAM_CHAR;
    }

    fclose(arquivo);

    CriaArquivoTxt(argv[1], arvore, bm, tamanhoTextoBits);

    return 0;
}

void CriaArquivoTxt(char *nomeArquivo, Arv *arvore, bitmap *mapaBits, int totalBitsTexto)
{
    int tamanhoNomeArquivo = strlen(nomeArquivo);

    // O comp tem tamanho 4 e txt tamanho 3, por isso o -1;
    tamanhoNomeArquivo--;

    char *nomeArquivoTxt = calloc(tamanhoNomeArquivo, sizeof(char));

    strcpy(nomeArquivoTxt, nomeArquivo);

    for (int i = 0; i < tamanhoNomeArquivo; i++)
    {
        if (nomeArquivoTxt[i] == '.')
        {
            nomeArquivoTxt[i + 1] = 't';
            nomeArquivoTxt[i + 2] = 'x';
            nomeArquivoTxt[i + 3] = 't';
            nomeArquivoTxt[i + 4] = '\0';

            break;
        }
    }

    FILE *arquivo = fopen(nomeArquivoTxt, "a");

    int cont = 0;
    unsigned char bit = 0;
    char caracter = '\0';

    Arv *arvoreBackupInicio = arvore;

    while (cont < totalBitsTexto)
    {
        bit = bitmapGetBit(mapaBits, cont);

        if (bit == 0)
        {
            arvore = RetornaArvoreEsquerda(arvore);

            if (RetornaTrueSeForFolha(arvore) == 1)
            {
                caracter = RetornaValorCharArvore(arvore);
                fprintf(arquivo, "%c", caracter);
                arvore = arvoreBackupInicio;
            }
        }
        else
        {
            arvore = RetornaArvoreDireita(arvore);

            if (RetornaTrueSeForFolha(arvore) == 1)
            {
                caracter = RetornaValorCharArvore(arvore);
                fprintf(arquivo, "%c", caracter);
                arvore = arvoreBackupInicio;
            }
        }

        cont++;
    }

    fclose(arquivo);
}