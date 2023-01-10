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