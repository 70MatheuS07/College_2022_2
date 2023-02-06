#include "geraBinario.h"

/**
 * @brief Compacta o tamanho do texto, o vetor de inteiro e o texto.
 *
 * @param arvore Árvore usada para compactação.
 * @param nomeArquivo Nome do arquivo.
 * @param vet Vetor de inteiros para fazer a árvore.
 */
void CompactaTodoArquivo(Arv *arvore, char *nomeArquivo, int vet[])
{
    bitmap *textoBits = CompactaTexto(arvore, nomeArquivo);

    unsigned long int totalBitsTexto = (bitmapGetLength(textoBits));

    int tamanhoNomeArquivo = strlen(nomeArquivo);

    // O txt tem tamanho 3 e comp tamanho 4 + /0, por isso o +2;
    tamanhoNomeArquivo += 2;

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

    fwrite(&totalBitsTexto, sizeof(unsigned long int), 1, arquivo);

    fwrite(vet, sizeof(int), NUM_ASCII, arquivo);

    int bytesArq = totalBitsTexto;
    unsigned char byte = 0;
    int cont = 0;

    for (int bytesArq = totalBitsTexto; bytesArq > 0; bytesArq -= 8)
    {
        byte = bitmapGetContents(textoBits)[cont];
        fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        cont++;
    }

    fclose(arquivo);

    bitmapLibera(textoBits);
    free(nomeArquivoCompactado);
}

/**
 * @brief Compacta o texto para dentro de um bitmap.
 *
 * @param arvore Árvore.
 * @param nomeArquivo Nome do arquivo.
 * @return bitmap*
 */
bitmap *CompactaTexto(Arv *arvore, char *nomeArquivo)
{
    int tamanho_texto = RetornaTamanhoTexto(nomeArquivo);

    // Multiplica pelo maior valor de um CHAR
    tamanho_texto = tamanho_texto * TAM_CHAR;

    char caracter = '\0';
    unsigned char valorBit = 0;

    char *binario = calloc(TAM_CHAR + 1, sizeof(char));

    bitmap *textoBits = bitmapInit(tamanho_texto);

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

            valorBit = binario[i] - 48;

            bitmapAppendLeastSignificantBit(textoBits, valorBit);
        }
    }

    fclose(arquivo);

    free(binario);

    return textoBits;
}

/**
 * @brief Retorna o tamanho do texto.
 *
 * @param nomeArquivo Nome do arquivo.
 * @return int
 */
int RetornaTamanhoTexto(char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");

    char lixo = '\0';
    int i = 0;

    while (fscanf(arquivo, "%c", &lixo) != EOF)
    {
        i++;
    }

    fclose(arquivo);

    return i;
}