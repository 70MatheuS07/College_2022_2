#include "ListaArv.h"

typedef struct celula tCelula;

struct celula
{
    Arv *arv;
    tCelula *prox;
};

struct listaArv
{
    tCelula *prim;
    tCelula *ult;
};

ListaArv *IniciaListaArv()
{
    ListaArv *listaArv = malloc(sizeof(ListaArv));
    listaArv->prim = NULL;
    listaArv->ult = NULL;

    return listaArv;
}

void InsereListaArv(ListaArv *lista, Arv *arv)
{
    tCelula *nova = malloc(sizeof(tCelula));
    nova->arv = arv;
    nova->prox = NULL;

    if (lista->prim == NULL)
    {
        lista->prim = nova;
        lista->ult = nova;
    }
    else
    {
        lista->ult->prox = nova;
        lista->ult = nova;
    }
}

void ImprimeListaArv(ListaArv *lista)
{
    tCelula *celula;
    for (celula = lista->prim; celula != NULL; celula = celula->prox)
    {
        Imprime(celula->arv);
    }
}
// essa função vai servir pra executar o algoritimo de Huffman
Arv *RetiraPrimeiraArvDaLista(ListaArv *lista)
{
    tCelula *p = lista->prim;
    Arv *arv;

    // lista vazia
    if (p == NULL)
    {
        return NULL;
    }
    arv = p->arv;
    // unica celula
    if (p == lista->prim && p == lista->ult)
    {
        lista->prim = NULL;
        lista->ult = NULL;
    }
    // primeira celula
    else if (p == lista->prim)
    {
        lista->prim = p->prox;
    }
    free(p);
    return arv;
}

void LiberaListaArv(ListaArv *lista)
{
    tCelula *p = lista->prim;
    tCelula *t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}
// Cria arvores para os caracteres com frequencia diferente de 0 e insere na lista
void PreencheListaArvFrequencia(ListaArv *lista, int V[], int tam)
{
    char c = '\0';

    for (int cont = 0; cont < tam; cont++)
    {
        c = cont;

        if (V[cont] != 0)
        {
            InsereListaArv(lista, CriaArv(V[cont], c));
        }
    }
}

int RetornaNumListaArv(ListaArv *lista)
{
    tCelula *celula;
    int num = 0;
    for (celula = lista->prim; celula != NULL; celula = celula->prox)
    {
        num++;
    }

    return num;
}

// Retorna a arvore de codificação de huffman
Arv* ExecutaAlgoritimoDeHuffman(ListaArv *lista)
{
    Arv *t1;
    Arv *t2;
    Arv *tr;
    while (RetornaNumListaArv(lista) > 1)
    {
        // n fiz
        OrdenaListaArvFrequencia(lista);

        t1 = RetiraPrimeiraArvDaLista(lista);
        t2 = RetiraPrimeiraArvDaLista(lista);

        tr = JuntaArvs(t1, t2);

        InsereListaArv(lista, tr);
    }
    return RetiraPrimeiraArvDaLista(lista);
}

void OrdenaListaArvFrequencia(ListaArv *lista)
{
    tCelula *pi;
    tCelula *pj;
    tCelula *pfim = NULL;

    if (lista->prim == NULL)
    {
        return;
    }

    for (pi = lista->prim; pi->prox != NULL; pi = pi->prox)
    {
        for (pj = lista->prim; pj->prox != pfim; pj = pj->prox)
        {
            if (RetornaFreqArv(pj->arv) > RetornaFreqArv(pj->prox->arv))
            {
                Arv *temp = pj->arv;
                pj->arv = pj->prox->arv;
                pj->prox->arv = temp;
            }
        }
        pfim = pj;
    }
}

Arv *RetornaArvListaArv(ListaArv *lista)
{
    return lista->prim->arv;
}