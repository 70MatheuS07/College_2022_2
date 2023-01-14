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
}
// essa função vai servir pra executar o algoritimo de Huffman
Arv *JuntaArvs(Arv *arv_e, Arv *arv_d)
{
    Arv *arv = malloc(sizeof(Arv));
    arv->frequencia = arv_e->frequencia + arv_d->frequencia;
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
/*
int ComparaFreqArv(void *arv_1, void *arv_2)
{
    Arv *arvore_1 = (Arv *)arv_1;
    Arv *arvore_2 = (Arv *)arv_2;

    return (arvore_1->frequencia - arvore_2->frequencia);
}
*/

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
                printf("\n caractere: %c, freq: %d\n\n", a->caractere, a->frequencia);
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