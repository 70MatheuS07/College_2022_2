#include "lista.h"

struct Lista
{
    union
    {
        tImovel *imovel;
        tMovel *movel;
    };

    int identificador;

    tLista *prox;
};

tLista *CriaLista()
{
    tLista *lista = NULL;

    return lista;
}

tLista *CriaListaEncadeada(tLista *lista)
{
    tLista *listaNova = malloc(sizeof(tLista));

    int identificador = 0;

    scanf("%d\n", &identificador);

    if (lista == NULL)
    {
        if (identificador == MOVEL)
        {
            listaNova->movel = CriaMovel();

            listaNova->identificador = identificador;
        }

        else if (identificador == IMOVEL)
        {
            listaNova->imovel = CriaImovel();

            listaNova->identificador = identificador;
        }

        listaNova->prox = NULL;
    }

    else
    {
        if (identificador == MOVEL)
        {
            listaNova->movel = CriaMovel();

            listaNova->identificador = identificador;
        }

        else if (identificador == IMOVEL)
        {
            listaNova->imovel = CriaImovel();

            listaNova->identificador = identificador;
        }

        listaNova->prox = lista;
    }

    return listaNova;
}

void ImprimeLista(tLista *lista)
{
    tLista *aux = lista;

    while (aux->prox != NULL)
    {
        if (aux->identificador == MOVEL)
        {
            ImprimeMovel(aux->movel);
        }

        else
        {
            ImprimeImovel(aux->imovel);
        }

        printf("\n");

        aux = aux->prox;
    }
}