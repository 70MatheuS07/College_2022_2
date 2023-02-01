#include "Arvore.h"

struct arv
{
    int frequencia;
    char caractere;
    Arv *e;
    Arv *d;
};

Arv *CriaArv_Vazia(void)
{
    return NULL;
}

Arv *CriaArv(int frequencia, char caractere)
{
    Arv *arv = malloc(sizeof(Arv));
    arv->e = NULL;
    arv->d = NULL;
    arv->frequencia = frequencia;
    arv->caractere = caractere;

    return arv;
}

void Imprime(Arv *a)
{
    if (a != NULL)
    {
        Imprime(a->e);
        printf("caractere: %c, freq: %d\n", a->caractere, a->frequencia);
        Imprime(a->d);
    }

    return;
}

// essa função vai servir pra executar o algoritimo de Huffman
Arv *JuntaArvs(Arv *arv_e, Arv *arv_d)
{
    Arv *arv = malloc(sizeof(Arv));
    arv->frequencia = arv_e->frequencia + arv_d->frequencia;
    arv->caractere = '\0';
    arv->e = arv_e;
    arv->d = arv_d;

    return arv;
}

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

int RetornaFreqArv(Arv *arvore)
{
    return arvore->frequencia;
}

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

int arv_vazia(Arv *a)
{
    if (a == NULL)
    {
        return 1;
    }

    return 0;
}

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

void TransformaInteiroBinarioLongInt(unsigned long int n, int *vet, int id)
{
    if (n == 0)
    {
        vet[id] = n;
    }
    else
    {
        TransformaInteiroBinarioLongInt(n / 2, vet, id - 1);
        vet[id] = n % 2;
    }
}

char RetornaValorCharArvore(Arv *arvore)
{
    return arvore->caractere;
}

Arv *RetornaArvoreEsquerda(Arv *arvore)
{
    return arvore->e;
}

Arv *RetornaArvoreDireita(Arv *arvore)
{
    return arvore->d;
}

int RetornaTrueSeForFolha(Arv *arvore)
{
    if (arvore->e == NULL && arvore->d == NULL)
    {
        return 1;
    }

    return 0;
}