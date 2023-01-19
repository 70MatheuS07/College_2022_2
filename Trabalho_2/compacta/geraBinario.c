#include "geraBinario.h"

void CompactaArvoreTexto(Arv *arvore, char *nomeArquivo)
{
    // falta tratar o nome do arquivo.

    FILE *arquivo = fopen(nomeArquivo, "ab");

    bitmap *arvoreBits = CompactaArvore(arvore);

    fclose(arquivo);
}

bitmap *CompactaArvore(Arv *arvore)
{
    int qtd_folhas = RetornaQtdFolhas(arvore);

    int qtd_nos = qtd_folhas - 1;

    int qtd_caracteres_folhas = qtd_folhas * TAM_CHAR;

    int total_bits = qtd_folhas + qtd_nos + qtd_caracteres_folhas + TAM_INT;

    bitmap *arvoreBits = bitmapInit(total_bits);

    int vetor[TAM_INT];

    for (int i = 0; i < TAM_INT; i++)
    {
        vetor[i] = 0;
    }

    TransformaInteiroBinario(qtd_folhas, vetor, TAM_INT - 1);

    for (int i = 0; i < TAM_INT; i++)
    {
        bitmapAppendLeastSignificantBit(arvoreBits, vetor[i]);
    }

    CaminhaArvoreRecurssiva(arvoreBits, arvore);

    /*

    if (bitmapGetMaxSize(arvoreBits) == bitmapGetLength(arvoreBits))
    {
        printf("\n\nTamanhos iguais\n\n");
    }

    printf("\n\n%d\n\n", bitmapGetLength(arvoreBits));

    printf("%0xh\n", bitmapGetContents(arvoreBits)[0]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[1]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[2]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[3]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[4]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[5]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[6]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[7]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[8]);
    printf("%0xh\n", bitmapGetContents(arvoreBits)[9]);
    //*/

    return arvoreBits;
}

bitmap *CompactaTexto(Arv *arvore, char *nomeArquivo)
{
}