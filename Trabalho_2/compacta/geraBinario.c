#include "geraBinario.h"

void CompactaArvoreTexto(Arv *arvore, char *nomeArquivo)
{
    // falta tratar o nome do arquivo.

    bitmap *arvoreBits = CompactaArvore(arvore);

    bitmap *textoBits = CompactaTexto(arvore, nomeArquivo);

    bitmap *arvoreTextoBits = CorrigiTamanhoTextoBits(nomeArquivo, arvore, textoBits);

    bitmap *arquivoBits = JuntaMapasDeBits(arvoreBits, textoBits);

    long long int totalBitsArquivo = (TAM_LONG_LONG_INT + bitmapGetLength(arquivoBits));

    // O inicio do arquivo sempre terá 64 bits direcionados para o long long int
    bitmap *arquivoFinalBits = JuntaTotalBitsComArquivoBits(totalBitsArquivo, arquivoBits);

    FILE *arquivo = fopen(nomeArquivo, "ab");

    

    fclose(arquivo);

    bitmapLibera(arvoreBits);
    bitmapLibera(textoBits);
    bitmapLibera(arvoreTextoBits);
    bitmapLibera(arquivoBits);
    bitmapLibera(arquivoFinalBits);
}

bitmap *CompactaArvore(Arv *arvore)
{
    int qtd_folhas = RetornaQtdFolhas(arvore);

    int qtd_nos = qtd_folhas - 1;

    int qtd_caracteres_folhas = qtd_folhas * TAM_CHAR;

    int total_bits = TAM_CHAR + qtd_nos + qtd_folhas + qtd_caracteres_folhas;

    bitmap *arvoreBits = bitmapInit(total_bits);

    int vetor[TAM_CHAR];

    for (int i = 0; i < TAM_CHAR; i++)
    {
        vetor[i] = 0;
    }

    TransformaInteiroBinario(qtd_folhas, vetor, TAM_CHAR - 1);

    for (int i = 0; i < TAM_CHAR; i++)
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
    tamanho_texto = tamanho_texto * TAM_CHAR;

    char caracter = '\0';
    int valorBit = 0;

    char *binario = calloc(TAM_CHAR + 1, sizeof(char));

    printf("\n\ntamanho texto: %d\n\n", tamanho_texto);

    bitmap *textoBits = bitmapInit(tamanho_texto);

    FILE *arquivo = fopen(nomeArquivo, "r");

    while (fscanf(arquivo, "%c", &caracter) != EOF)
    {
        for (int i = 0; i < TAM_CHAR + 1; i++)
        {
            binario[i] = '\0';
        }

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

    fclose(arquivo);

    free(binario);
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

    char lixo = '\0';
    int i = 0;

    while (fscanf(arquivo, "%c", &lixo) != EOF)
    {
        i++;
    }

    printf("\n\n%d\n\n", i);
    fclose(arquivo);

    return i;
}

bitmap *CorrigiTamanhoTextoBits(char *nomeArquivo, Arv *arvore, bitmap *textoBits)
{
    char caracter = '\0';
    int total = 0;

    char *binario = calloc(TAM_CHAR + 1, sizeof(char));

    FILE *arquivo = fopen(nomeArquivo, "r");

    while (fscanf(arquivo, "%c", &caracter) != EOF)
    {
        for (int i = 0; i < TAM_CHAR + 1; i++)
        {
            binario[i] = '\0';
        }

        VarreArvore(arvore, caracter, INICIALIZA_NUM, binario);

        for (int i = 0; i < TAM_CHAR + 1; i++)
        {
            if (binario[i] == '\0')
            {
                break;
            }
            else
            {
                total++;
            }
        }
    }

    fclose(arquivo);

    bitmap *totalRealBits = bitmapInit(total);

    unsigned char bit = 0;

    for (int i = 0; i < total; i++)
    {
        bit = bitmapGetBit(textoBits, i);
        bitmapAppendLeastSignificantBit(totalRealBits, bit);
    }

    int num1 = bitmapGetMaxSize(totalRealBits);
    int num2 = bitmapGetMaxSize(textoBits);

    printf("\n%d  %d\n", num1, num2);

    free(binario);

    return totalRealBits;
}

bitmap *JuntaMapasDeBits(bitmap *arvoreBits, bitmap *textoBits)
{
    int num1 = bitmapGetLength(arvoreBits);

    int num2 = bitmapGetLength(textoBits);

    int numTotal = 0;
    numTotal = num1 + num2;

    bitmap *mapaBits = bitmapInit(numTotal);

    unsigned char bit;

    int j = 0;

    for (int i = 0; i < numTotal; i++)
    {
        if (i < num1)
        {
            bit = bitmapGetBit(arvoreBits, i);
        }

        else
        {
            bit = bitmapGetBit(textoBits, j);
            j++;
        }

        bitmapAppendLeastSignificantBit(mapaBits, bit);
    }

    /*

    printf("\n%d\n", num1);
    printf("\n%d\n", num2);
    printf("\n%d\n", numTotal);

    printf("\n\n");
    printf("%0xh\n", bitmapGetContents(mapaBits)[0]);
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
    printf("%0xh\n", bitmapGetContents(mapaBits)[13]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[14]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[15]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[16]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[17]);
    printf("%0xh\n", bitmapGetContents(mapaBits)[18]);
    printf("\n");
    */

    return mapaBits;
}

bitmap *JuntaTotalBitsComArquivoBits(long long int numTotalBits, bitmap *arvoreTextoBits)
{
    int vetor[TAM_LONG_LONG_INT];

    for (int i = 0; i < TAM_LONG_LONG_INT; i++)
    {
        vetor[i] = '\0';
    }

    TransformaInteiroBinario(numTotalBits, vetor, TAM_LONG_LONG_INT - 1);

    bitmap *mapaBitsFinal = bitmapInit(numTotalBits);

    unsigned char bit;

    int j = 0;

    for (int i = 0; i < numTotalBits; i++)
    {
        if (i < TAM_LONG_LONG_INT)
        {
            bit = vetor[i];
        }

        else
        {
            bit = bitmapGetBit(arvoreTextoBits, j);
            j++;
        }

        bitmapAppendLeastSignificantBit(mapaBitsFinal, bit);
    }

    return mapaBitsFinal;
}