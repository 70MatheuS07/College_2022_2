#include "listaLike.h"

typedef struct Celula tCelula;

struct Celula
{
    tLike *like;
    tCelula *prox;
};

struct ListaLike
{
    tCelula *inicio;
    tCelula *fim;
};

tListaLike *CriaListaLike()
{
    tListaLike *listaLike = malloc(sizeof(tListaLike));

    listaLike->inicio = NULL;
    listaLike->fim = NULL;

    return listaLike;
}

void InsereLikeLista(tListaLike *listaLike, tLike *like)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->like = like;
    nova->prox = NULL;

    if (listaLike->inicio == NULL)
    {
        listaLike->inicio = listaLike->fim = nova;
    }

    else
    {
        listaLike->fim->prox = nova;
        listaLike->fim = nova;
    }
}

void RetiraDaListaLike(tListaLike *listaLike, char *nome)
{

    tCelula *p = listaLike->inicio;
    tCelula *ant = NULL;

    while (p != NULL && EhNomeLikeIgual(p->like, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return;
    }

    // unica celula
    if (p == listaLike->inicio && p == listaLike->fim)
    {

        listaLike->inicio = NULL;
        listaLike->fim = NULL;
    }

    // primeira celula
    else if (p == listaLike->inicio)
    {
        listaLike->inicio = p->prox;
    }

    // ultima celula
    else if (p == listaLike->fim)
    {
        listaLike->fim = ant;
        listaLike->fim->prox = NULL;
    }
    
    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    LiberaLike(p->like);
    free(p);
}

void LiberaListaLike(tListaLike *listaLike)
{
    tCelula *p = listaLike->inicio;
    tCelula *t;

    while (p != NULL)
    {
        t = p->prox;
        LiberaLike(p->like);

        free(p);
        p = NULL;

        p = t;
    }

    free(listaLike);
    listaLike = NULL;
}

void ImprimeListaLike(tListaLike *listaLike)
{
    tCelula *celula;
    for (celula = listaLike->inicio; celula != NULL; celula = celula->prox)
    {
        ImprimeLike(celula->like);
    }
}

int ComparaListaLikeNome(tListaLike *lista, char *nome)
{
    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        if (ComparaSeNomeLikeIgualNome(aux->like, nome) == 1)
        {
            return 1;
        }
    }

    return 0;
}

void LiberaListaLikeEdMatch(tListaLike *listaLike)
{
    tCelula *p = listaLike->inicio;
    tCelula *t;
    char* nome;
    while (p != NULL)
    {
        t = p->prox;

        free(p);
        p = NULL;

        p = t;
    }

    free(listaLike);
    listaLike = NULL;
}

int RetiraDaListaLikeEdMatch(tListaLike *listaLike, char *nome)
{
    tCelula *p = listaLike->inicio;
    tCelula *ant = NULL;

    while (p != NULL && EhNomeLikeIgual(p->like, nome) != 0)
    {
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return 0;
    }
    

    // unica celula
    if (p == listaLike->inicio && p == listaLike->fim)
    {

        listaLike->inicio = NULL;
        listaLike->fim = NULL;
    }

    // primeira celula
    else if (p == listaLike->inicio)
    {
        listaLike->inicio = p->prox;
    }

    // ultima celula
    else if (p == listaLike->fim)
    {
        listaLike->fim = ant;
        listaLike->fim->prox = NULL;
    }

    // entre duas celulas
    else
    {
        ant->prox = p->prox;
    }

    free(p);
    return 1;
}

int ProcuraNomeListaLike(tListaLike *listaLike, char *nome)
{
    for (tCelula *aux = listaLike->inicio; aux != NULL; aux = aux->prox)
    {
        if (strcmp(nome, RetornaNomeLike(aux->like)) == 0)
        {
            return 1;
        }
    }

    return 0;
}