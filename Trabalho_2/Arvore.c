#include "Arvore.h"

struct arv
{
    int frequencia;
    unsigned char caractere;
    Arv *e;
    Arv *d;
};

/**
 * @brief Somente retorna NULL para arvore.
 *
 * @return Arv*
 */
Arv *CriaArv_Vazia(void)
{
    return NULL;
}

/**
 * @brief Abre espaço na memória e coloca
 *        a frequência e o caracter especifico.
 *
 * @param frequencia Quantidade de vezes que esse caracter aparece.
 * @param caractere O caracter específico.
 * @return Arv*
 */
Arv *CriaArv(int frequencia, char caractere)
{
    Arv *arv = malloc(sizeof(Arv));
    arv->e = NULL;
    arv->d = NULL;
    arv->frequencia = frequencia;
    arv->caractere = caractere;

    return arv;
}

/**
 * @brief Imprime da esquerda para a direita.
 *
 * @param a Árvore.
 */
void Imprime(Arv *a)
{
    if (a != NULL)
    {
        printf("caractere: %c, freq: %d\n", a->caractere, a->frequencia);
        Imprime(a->e);
        Imprime(a->d);
    }

    return;
}

/**
 * @brief Junta duas arvores em uma arvore só
 *
 * @param arv_e Árvore da esquerda.
 * @param arv_d Árvore da direita.
 * @return Arv*
 */
Arv *JuntaArvs(Arv *arv_e, Arv *arv_d)
{
    Arv *arv = malloc(sizeof(Arv));
    arv->frequencia = arv_e->frequencia + arv_d->frequencia;
    arv->caractere = '\0';
    arv->e = arv_e;
    arv->d = arv_d;

    return arv;
}

/**
 * @brief Libera memória da arvore.
 *
 * @param a Árvore a ser liberada.
 * @return Arv*
 */
Arv *Libera(Arv *a)
{
    if (a != NULL)
    {
        Libera(a->e);
        Libera(a->d);
        free(a);
    }

    return NULL;
}

/**
 * @brief Retorna frequencia da arvore.
 *
 * @param arvore Árvore para devolver frequência.
 * @return int
 */
int RetornaFreqArv(Arv *arvore)
{
    return arvore->frequencia;
}

/**
 * @brief Caminha na arvore e adiciona caracteres
 *        a medida que anda nela e insere no vetor.
 *
 * @param a Árvore a ser percorrida.
 * @param caractere Caracter será usado na recursividade.
 * @param num Auxiliador na concatenação.
 * @param palavra String com os "bits" salvos.
 * @return int
 */
int VarreArvore(Arv *a, char caractere, int num, char *palavra)
{
    if (a != NULL)
    {
        // fazer a concatenação
        if (num == 0)
            strcat(palavra, "0");

        else if (num == 1)
            strcat(palavra, "1");

        // se for folha
        if (a->e == NULL && a->d == NULL)
        {
            // se for o caractere
            if (a->caractere == caractere)
            {
                return 1;
            }
            // limpar o último caractere da palavra
            else
            {
                for (int i = 0;; i++)
                {
                    if (palavra[i] == '\0')
                    {
                        palavra[i - 1] = '\0';
                        break;
                    }
                }

                return 0;
            }
        }

        // concatenar um 0 na palavra
        if (VarreArvore(a->e, caractere, 0, palavra) == 1)
        {
            return 1;
        }

        // concatenar um 1 na palavra
        if (VarreArvore(a->d, caractere, 1, palavra) == 1)
        {
            return 1;
        }

        else
        {
            for (int i = 0;; i++)
            {
                if (palavra[i] == '\0')
                {
                    palavra[i - 1] = '\0';
                    break;
                }
            }
        }
    }

    return 0;
}

/**
 * @brief Retorna a quantidade de folhas da árvore.
 *
 * @param a Árvore a ser somada suas folhas.
 * @return int
 */
int RetornaQtdFolhas(Arv *a)
{
    if (arv_vazia(a))
    {
        return 0;
    }

    if (arv_vazia(a->e) || arv_vazia(a->d))
    {
        return 1;
    }

    return (RetornaQtdFolhas(a->e) + RetornaQtdFolhas(a->d));
}

/**
 * @brief Insere os caracteres da arvore no mapa de bits.
 *
 * @param mapaBits Mapa de bits.
 * @param arvore Árvore a ser caminhada.
 * @return int
 */
int CaminhaArvoreRecurssiva(bitmap *mapaBits, Arv *arvore)
{
    if (arvore != NULL)
    {
        if (arvore->e == NULL && arvore->d == NULL)
        {
            bitmapAppendLeastSignificantBit(mapaBits, 1);

            int letra = arvore->caractere;

            int vetor[TAM_CHAR];

            for (int i = 0; i < TAM_CHAR; i++)
            {
                vetor[i] = 0;
            }

            TransformaInteiroBinario(letra, vetor, TAM_CHAR - 1);

            for (int i = 0; i < TAM_CHAR; i++)
            {
                bitmapAppendLeastSignificantBit(mapaBits, vetor[i]);
            }
        }
        else
        {
            bitmapAppendLeastSignificantBit(mapaBits, 0);
        }

        CaminhaArvoreRecurssiva(mapaBits, arvore->e);
        CaminhaArvoreRecurssiva(mapaBits, arvore->d);

        return 1;
    }

    return 0;
}

/**
 * @brief Retorna o valor 1 caso a arvore seja NULL.
 *
 * @param a Árvore a ser verificada se vazia ou não.
 * @return int
 */
int arv_vazia(Arv *a)
{
    if (a == NULL)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Transforma um número inteiro em valores int em um vetor,
 *        que representa o binário.
 *
 * @param n O número a ser dividido na função.
 * @param vet Vetor de inteiros que salva os "bits".
 * @param id Posição final do vetor de inteiros.
 */
void TransformaInteiroBinario(int n, int *vet, int id)
{
    if (n == 0)
    {
        vet[id] = n;
    }
    else
    {
        TransformaInteiroBinario(n / 2, vet, id - 1);
        vet[id] = n % 2;
    }
}

/**
 * @brief Retorna o caracter de dentro da árvore.
 *
 * @param arvore Árvore a ser retornado o seu caracter.
 * @return char
 */
char RetornaValorCharArvore(Arv *arvore)
{
    return arvore->caractere;
}

/**
 * @brief Retorna a árvore da esquerda.
 *
 * @param arvore Árvore usada para o retorno.
 * @return Arv*
 */
Arv *RetornaArvoreEsquerda(Arv *arvore)
{
    return arvore->e;
}

/**
 * @brief Retorna a árvore da direita.
 *
 * @param arvore Árvore usada para o retorno.
 * @return Arv*
 */
Arv *RetornaArvoreDireita(Arv *arvore)
{
    return arvore->d;
}

/**
 * @brief Retorna TRUE (1) se for folha.
 *
 * @param arvore Árvore usada para o retorno.
 * @return int
 */
int RetornaTrueSeForFolha(Arv *arvore)
{
    if (arvore->e == NULL && arvore->d == NULL)
    {
        return 1;
    }

    return 0;
}