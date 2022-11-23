#include "listaFeed.h"

typedef struct Celula tCelula;

struct Celula
{
    tFeed *feed;
    tCelula *prox;
};

struct ListaFeed
{
    tCelula *inicio;
    tCelula *fim;
};

tListaFeed *CriaListaFeed()
{
    tListaFeed *listaFeed = malloc(sizeof(tListaFeed));

    listaFeed->inicio = NULL;
    listaFeed->fim = NULL;

    return listaFeed;
}

void InsereFeedLista(tListaFeed *listaFeed, tFeed *feed)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->feed = feed;
    nova->prox = NULL;

    if (listaFeed->inicio == NULL)
    {
        listaFeed->inicio = listaFeed->fim = nova;
    }

    else
    {
        listaFeed->fim->prox = nova;
        listaFeed->fim = nova;
    }
}

void LiberaListaFeed(tListaFeed *listaFeed)
{
    tCelula *p = listaFeed->inicio;
    tCelula *t;

    while (p != NULL)
    {
        t = p->prox;
        LiberaFeed(p->feed);

        free(p);
        p = NULL;

        p = t;
    }

    free(listaFeed);
    listaFeed = NULL;
}

void ColocaNomeMensagemNaListaFeed(tListaFeed *listaFeed, char *nome, char *mensagem)
{
    tFeed *feed = CriaFeed(nome, mensagem);

    InsereFeedLista(listaFeed, feed);
}

void ImprimeListaFeed(tListaFeed *listaFeed, FILE *arquivo)
{
    fprintf(arquivo, "POSTS DO FEED\n");

    for (tCelula *aux = listaFeed->inicio; aux != NULL; aux = aux->prox)
    {
        ImprimeFeed(aux->feed, arquivo);
    }
}