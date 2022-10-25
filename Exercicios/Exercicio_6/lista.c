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

    while (aux != NULL)
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

tLista *RetiraLista(tLista *lista, int id)
{
    tLista *aux = lista;
    tLista *ant = NULL;

    while (aux != NULL)
    {
        if (aux->identificador == MOVEL)
        {
            if (RetornaIdMovel(aux->movel) == id)
            {
                break;
            }
        }

        else
        {
            if (RetornaIdImovel(aux->imovel) == id)
            {
                break;
            }
        }

        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("Nao existe esse id\n");
        return lista;
    }

    if (ant == NULL)
    {
        lista = aux->prox;

        LiberaLista(aux);
    }

    else if (aux->prox == NULL)
    {
        ant->prox = NULL;

        LiberaLista(aux);
    }

    else
    {
        ant->prox = aux->prox;

        LiberaLista(aux);
    }

    return lista;
}

void LiberaLista(tLista *lista)
{
    if (lista->identificador == MOVEL)
    {
        LiberaMovel(lista->movel);
    }

    else
    {
        LiberaImovel(lista->imovel);
    }

    lista->prox = NULL;

    free(lista);
}

void LiberaListaToda(tLista *lista)
{
    while (lista != NULL)
    {
        if (lista->identificador == MOVEL)
        {
            LiberaMovel(lista->movel);
        }

        else
        {
            LiberaImovel(lista->imovel);
        }

        free(lista);

        lista = lista->prox;
    }

    lista = NULL;
}