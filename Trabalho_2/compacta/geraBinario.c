#include "geraBinario.h"

void CompactaArvoreTexto(Arv *arvore, char *nomeArquivo)
{
    // falta tratar o nome do arquivo.

    FILE *arquivo = fopen(nomeArquivo, "ab");

    bitmap *arvoreBits = CompactaArvore(arvore);

    bitmap *textoBits = CompactaTexto(arvore, nomeArquivo);

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
    int tamanho_texto = RetornaTamanhoTexto(nomeArquivo);

    // Multiplica pelo maior valor de um CHAR
    tamanho_texto *= TAM_CHAR;

    FILE *arquivo = fopen(nomeArquivo, "r");

    char caracter;
    int valorBit;

    char *binario = calloc(TAM_CHAR + 1, sizeof(char));

    printf("\n\ntamanho texto: %d\n\n", tamanho_texto);

    bitmap *textoBits = bitmapInit(tamanho_texto);

    while (1)
    {
        for (int i = 0; i < TAM_CHAR + 1; i++)
        {
            binario[i] = '\0';
        }

        if (feof(arquivo))
        {
            break;
        }

        fscanf(arquivo, "%c", &caracter);

        VarreArvore(arvore, caracter, INICIALIZA_NUM, binario);

        printf("caracter: %c, binario: %s\n", caracter, binario);

        for (int i = 0; i < TAM_CHAR + 1; i++)
        {
            if (binario[i] == '\0')
            {
                break;
            }

            valorBit = binario[i] - 48;

            bitmapAppendLeastSignificantBit(textoBits, valorBit);
        }
    }
    /*
    printf("\n\n");
    printf("%0xh\n", bitmapGetContents(textoBits)[0]);
    printf("%0xh\n", bitmapGetContents(textoBits)[1]);
    printf("%0xh\n", bitmapGetContents(textoBits)[2]);
    printf("%0xh\n", bitmapGetContents(textoBits)[3]);
    printf("%0xh\n", bitmapGetContents(textoBits)[4]);
    printf("%0xh\n", bitmapGetContents(textoBits)[5]);
    printf("%0xh\n", bitmapGetContents(textoBits)[6]);
    printf("%0xh\n", bitmapGetContents(textoBits)[7]);
    printf("%0xh\n", bitmapGetContents(textoBits)[8]);
    printf("%0xh\n", bitmapGetContents(textoBits)[9]);
    printf("\n");

    */

    return textoBits;
}

int RetornaTamanhoTexto(char *nomeArquivo)
{
    FILE *arquivo = fopen("arq.txt", "r");

    char lixo;
    int i = 0;

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%c", &lixo);
        i++;
    }

    fclose(arquivo);

    // BUG DE LEITURA, SEMPRE LÊ 1 CARACTER A MAIS
    i--;

    return i;
}