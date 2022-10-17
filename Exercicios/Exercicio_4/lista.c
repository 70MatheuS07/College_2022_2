#include "lista.h"

typedef struct Celula tCelula;

struct Celula
{
    tProduto *produto;
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

void InsereProdutoLista(tProduto *produto)
{
    tProduto *produto;

    produto = CriaProduto();

    InsereProdutoLista(produto);
}

void InsereProdutoLista(tLista *lista, tProduto *produto)
{
    tCelula *nova = malloc(sizeof(tCelula));

    nova->produto = produto;
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

void RetiraProdutoLista(tLista *lista, int codigo)
{
    tCelula *aux = lista->inicio;
    tCelula *ant;
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

        ant = aux;
        aux = aux->prox;
    }

    if (aux == lista->inicio)
    {
        lista->inicio = aux->prox;

        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else if (aux == lista->fim)
    {
        lista->fim = ant;

        LiberaProduto(aux->produto);
        aux->prox = NULL;
        free(aux);
        aux = NULL;
    }

    else
    {
        
    }
}