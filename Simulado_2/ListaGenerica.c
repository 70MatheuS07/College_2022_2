#include "ListaGenerica.h"

typedef struct Celula tCelula;

struct Celula
{
    void *pessoa;
    tCelula *prox;
};

struct ListaGenerica
{
    tCelula *inicio;
    tCelula *fim;
};

tListaGenerica *CriaListaGenerica()
{
    tListaGenerica *lista = malloc(sizeof(tListaGenerica));

    lista->inicio = NULL;
    lista->fim = NULL;
    
    return lista;
}

void InserePessoaListaGenerica(tListaGenerica *lista, void *pessoa)
{
    tCelula *nova = malloc(sizeof(tCelula));
    tCelula *ultima;
    nova->pessoa = pessoa;
    nova->prox = NULL;

    if(lista->inicio == NULL && lista->fim == NULL)
    {
        lista->inicio = nova;
        lista->fim = nova;
    }

    else
    {
        lista->fim->prox = nova;
        lista->fim = nova;
    }
}