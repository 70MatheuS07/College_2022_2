#include "TadLista.h"

typedef struct Celula tCelula;

struct Celula
{
    tPalavra *palavra;
    tCelula *prox;
};

struct Lista
{
    tCelula *inicio;
    tCelula *fim;
};

tLista *CriaLista()
{
    tLista *lista = malloc(sizeof(tLista));

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

void InserePalavraLista(tLista *lista, tPalavra *palavra)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->palavra = palavra;
    nova->prox = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = lista->fim = nova;
    }

    else
    {
        lista->fim->prox = nova;
        lista->fim = nova;
    }
}

tPalavra *BuscaPalavraLista(tLista *lista, char *string)
{
    tCelula *aux = lista->inicio;
    tCelula *ant;
    char *palavraRtn;

    while (1)
    {
        palavraRtn = RetornaStringPalavra(aux->palavra);

        if (strcmp(string, palavraRtn) == 0)
        {
            break;
        }

        if (aux == NULL)
        {
            printf("\nNao existe essa palavra na lista");
            return NULL;
        }

        ant = aux;
        aux = aux->prox;
    }

    return aux->palavra;
}

void ImprimeLista(tLista *lista)
{
    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        ImprimePalavra(aux->palavra);
    }
}

void LiberaLista(tLista *lista)
{
    tCelula *aux, *prox;

    aux = lista->inicio;

    while (aux != NULL)
    {
        prox = aux->prox;

        LiberaPalavra(aux->palavra);
        free(aux);

        aux = prox;
    }

    free(lista);
    lista = NULL;
}