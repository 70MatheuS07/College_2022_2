#include "geraBinario.h"

void CompactaArvoreTexto(Arv *arvore, char *nomeArquivo)
{
    // falta tratar o nome do arquivo.

    bitmap *arvoreBits = CompactaArvore(arvore);

    bitmap *textoBits = CompactaTexto(arvore, nomeArquivo);

    bitmap *arvoreTextoBits = CorrigiTamanhoTextoBits(nomeArquivo, arvore, textoBits);

    bitmap *arquivoBits = JuntaMapasDeBits(arvoreBits, textoBits);

    /*-----------------------------Acrescenta long long int no inicio dentro do bitmap----------------------*/

    unsigned long int totalBitsArquivo = (TAM_LONG_INT + bitmapGetLength(arquivoBits));
    printf("\nlength %d\n", bitmapGetLength(arquivoBits));

    // bitmap *arquivoFinalBits = JuntaTotalBitsComArquivoBits(totalBitsArquivo, arquivoBits);

    /*------------------------------------------------------------------------------------------------------*/

    // unsigned char *pointer = bitmapGetContents(arquivoFinalBits);

    // unsigned int tamanhoBitsArquivo = bitmapGetLength(arquivoFinalBits);

    /*---------------------------------Faz a mudança do .txt para .comp-------------------------------------*/

    int tamanhoNomeArquivo = strlen(nomeArquivo);

    // O txt tem tamanho 3 e comp tamanho 4, por isso o +1;
    tamanhoNomeArquivo++;

    char *nomeArquivoCompactado = calloc(tamanhoNomeArquivo, sizeof(char));

    strcpy(nomeArquivoCompactado, nomeArquivo);

    for (int i = 0; i < tamanhoNomeArquivo; i++)
    {
        if (nomeArquivoCompactado[i] == '.')
        {
            nomeArquivoCompactado[i + 1] = 'c';
            nomeArquivoCompactado[i + 2] = 'o';
            nomeArquivoCompactado[i + 3] = 'm';
            nomeArquivoCompactado[i + 4] = 'p';
            nomeArquivoCompactado[i + 5] = '\0';

            break;
        }
    }

    /*-------------------------------------------------------------------------------------------------------*/

    FILE *arquivo = fopen(nomeArquivoCompactado, "wb");

    fwrite(&totalBitsArquivo, sizeof(unsigned long int), 1, arquivo);

    int bytesArq = totalBitsArquivo - 32;
    unsigned char byte;
    printf("conteudo compacta\n");
    for (int cont = 0; bytesArq > 0; cont++)
    {

        byte = bitmapGetContents(arquivoBits)[cont];
        printf("%0xh\n", bitmapGetContents(arquivoBits)[cont]);
        //printf("%d ", byte);
        fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        bytesArq = bytesArq - 8;
    }
    /*
    if (totalBitsArquivo % 8 == 0)
    {
        fwrite((bitmapGetContents(arquivoBits)), sizeof(unsigned char), totalBitsArquivo / 8, arquivo);
    }
    else
    {
        fwrite((bitmapGetContents(arquivoBits)), sizeof(unsigned char), (totalBitsArquivo / 8) + 1, arquivo);
    }

    fclose(arquivo);
    */

    /*

    bitmap *teste;

    FILE *arquivoLeh = fopen("arquivo.comp", "rb");

    fread(teste, sizeof(char), (1024 * 1024), arquivoLeh);

    fclose(arquivoLeh);

    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[0]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[1]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[2]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[3]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[4]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[5]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[6]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[7]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[8]);
    printf("%0xh\n", bitmapGetContents(arquivoFinalBits)[9]);

    printf("\n\n");

    printf("%0xh\n", bitmapGetContents(teste)[0]);
    printf("%0xh\n", bitmapGetContents(teste)[1]);
    printf("%0xh\n", bitmapGetContents(teste)[2]);
    printf("%0xh\n", bitmapGetContents(teste)[3]);
    printf("%0xh\n", bitmapGetContents(teste)[4]);
    printf("%0xh\n", bitmapGetContents(teste)[5]);
    printf("%0xh\n", bitmapGetContents(teste)[6]);
    printf("%0xh\n", bitmapGetContents(teste)[7]);
    printf("%0xh\n", bitmapGetContents(teste)[8]);
    printf("%0xh\n", bitmapGetContents(teste)[9]);

    */

    bitmapLibera(arvoreBits);
    bitmapLibera(textoBits);
    bitmapLibera(arvoreTextoBits);
    bitmapLibera(arquivoBits);
    //bitmapLibera(arquivoFinalBits);
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

    return mapaBits;
}

bitmap *JuntaTotalBitsComArquivoBits(long long int numTotalBits, bitmap *arvoreTextoBits)
{
    int vetor[TAM_LONG_INT];

    for (int i = 0; i < TAM_LONG_INT; i++)
    {
        vetor[i] = '\0';
    }

    TransformaInteiroBinarioLongLong(numTotalBits, vetor, TAM_LONG_INT - 1);

    bitmap *mapaBitsFinal = bitmapInit(numTotalBits);

    unsigned char bit;

    int j = 0;

    for (int i = 0; i < numTotalBits; i++)
    {
        if (i < TAM_LONG_INT)
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