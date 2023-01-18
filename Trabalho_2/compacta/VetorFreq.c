#include "VetorFreq.h"

/**
 * @brief Zera os valores da frequencia do vetor.
 *
 * @param V
 * @param tam
 */
void ZeraVetorFreq(int V[], int tam)
{
    for (int cont = 0; cont < tam; cont++)
    {
        V[cont] = 0;
    }
}

/**
 * @brief Abre o arquivo e preenche o vetor com o caracter especifico
 *        e sua frequência.
 *
 * @param V
 * @param tam
 * @param nomeArq
 */
void PreencheVetorFreq(int V[], int tam, char *nomeArq)
{
    FILE *file;
    file = fopen(nomeArq, "r");

    if (file == NULL)
    {
        printf("\nnão abriu o arquivo %s\n\n", nomeArq);
        return;
    }
    char caractere = '\0';

    while (!feof(file))
    {
        fscanf(file, "%c", &caractere);
        V[caractere]++;
    }

    // Problema de bug de duplicacao do ultimo caracter do arq.txt
    V[caractere]--;

    fclose(file);
}

/**
 * @brief Imprime o vetor de frequência.
 *
 * @param V
 * @param tam
 */
void ImprimeVetorFreq(int V[], int tam)
{
    char c = '\0';

    for (int cont = 0; cont < tam; cont++)
    {
        c = cont;
        printf("\n%c = %d\n", c, V[cont]);
    }
}