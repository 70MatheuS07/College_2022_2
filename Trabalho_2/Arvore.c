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