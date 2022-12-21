#include "listaGenerica.h"

struct ListaGenerica
{
    void *item;
    tListaGenerica *prox;
};

tListaGenerica *CriaListaGenericaVazia()
{
    return NULL;
}

tListaGenerica *InsereItemListaGenerica(tListaGenerica *lista, void *item)
{
    tListaGenerica *nova = (tListaGenerica *)malloc(sizeof(tListaGenerica));

    nova->item = item;
    nova->prox = lista;

    return nova;
}

tListaGenerica *RetiraItemListaGenerica(tListaGenerica *lista, int (*cb)(void *, void *), void *chave)
{
    tListaGenerica *aux = lista;
    tListaGenerica *anterior = NULL;

    while (aux != NULL && cb(aux->item, chave))
    {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        return lista;
    }

    if (anterior == NULL)
    {
        lista = lista->prox;
    }

    else
    {
        anterior->prox = aux->prox;
    }

    free(aux);

    return lista;
}

int PercorreListaGenerica(tListaGenerica *lista, int (*cb)(void *, void *), void *dado)
{
    int result = 0;

    for (tListaGenerica *aux = lista; aux != NULL; aux = aux->prox)
    {
        result = cb(aux->item, dado);

        if (result == 0)
        {
            return result;
        }
    }

    return 1;
}

void LiberaListaGenerica(tListaGenerica *lista)
{
    tListaGenerica *aux = lista;
    tListaGenerica *prox;

    while (aux != NULL)
    {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(lista);
    lista = NULL;
}