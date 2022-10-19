#include "lista.h"

typedef struct Celula tCelula;

struct Celula
{
    tProduto *produto;
    tCelula *prox;
    tCelula *ant;
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

void InsereProdutoLista(tLista *lista, tProduto *produto)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->produto = produto;

    if (lista->inicio == NULL)
    {
        nova->prox = NULL;
        nova->ant = NULL;
        lista->inicio = lista->fim = nova;
    }

    else
    {
        lista->fim->prox = nova;
        nova->ant = lista->fim;
        nova->prox = NULL;
        lista->fim = nova;
    }
}

void RetiraProdutoLista(tLista *lista, int codigo)
{
    tCelula *aux = lista->inicio;
    int codigoReturn;

    while (1)
    {
        codigoReturn = RetornaCodigoProduto(aux->produto);

        if (codigoReturn == codigo)
        {
            break;
        }

        if (aux == NULL)
        {
            printf("\nNao existe esse produto para ser retirado");
            return;
        }

        aux = aux->prox;
    }

    if (aux == lista->inicio && aux == lista->fim)
    {
        lista->inicio = NULL;
        lista->fim = NULL;

        LiberaProduto(aux->produto);
        aux->ant = NULL;
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else if (aux == lista->inicio)
    {
        lista->inicio = aux->prox;
        aux->prox->ant = NULL;

        LiberaProduto(aux->produto);
        aux->ant = NULL;
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else if (aux == lista->fim)
    {
        aux->ant->prox = NULL;
        lista->fim = aux->ant;
        

        LiberaProduto(aux->produto);
        aux->ant = NULL;
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else
    {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }
}

void ImprimeLista(tLista *lista)
{
    for (tCelula *aux = lista->inicio; aux != NULL; aux = aux->prox)
    {
        ImprimeProduto(aux->produto);
    }
}

void LiberaLista(tLista *lista)
{
    tCelula *aux, *prox;

    aux = lista->inicio;

    while (aux != NULL)
    {
        prox = aux->prox;

        LiberaProduto(aux->produto);
        free(aux);

        aux = prox;
    }

    free(lista);
    lista = NULL;
}

void ImprimeListaInvertida(tLista *lista)
{
    for (tCelula *aux = lista->fim; aux != NULL; aux = aux->ant)
    {
        ImprimeProduto(aux->produto);
    }
}