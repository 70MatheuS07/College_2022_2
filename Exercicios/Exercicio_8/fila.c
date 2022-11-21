#include "fila.h"

struct Fila
{
    int n;
    int max;
    int inicio;
    tPedido **pedidos;
};

tFila *CriaFila(int tam)
{
    tFila *fila = malloc(sizeof(tFila));

    fila->pedidos = CriaPedido(tam);

    fila->max = tam;
    fila->inicio = 0;
    fila->n = 0;

    return fila;
}

void InsereFila(tFila *fila, tPedido *pedido)
{
    if (fila->n >= fila->max)
    {
        printf("\nFila cheia ou invalida!");
        return;
    }

    int fim = (fila->inicio + fila->n) % fila->max;

    fila->pedidos[fim] = pedido;
    fila->n++;
}

tLista *RetiraFila(tFila *fila)
{
    if (fila == NULL || fila->inicio == 0)
    {
        printf("Fila vazia\n");
        return;
    }

    tPedido *pedido = fila->pedidos[fila->inicio];

    fila->inicio = (fila->inicio + 1) % fila->max;

    fila->n--;

    /*
    if (fila->inicio == fila->max)
    {
        fila->pedidos[fila->inicio] = NULL;
        fila->inicio = 0;
        fila->n--;
        return;
    }

    fila->pedidos[fila->inicio] = NULL;
    fila->inicio++;
    fila->n--;
    */

   return pedido;
}

void LiberaFila(tFila *fila)
{
    int i = 0;
    int posicao;

    for (i = fila->inicio; i < fila->n; i++)
    {
        posicao = (fila->inicio + i) % fila->max;
        LiberaLista(fila->pedidos[posicao]);
    }

    free(fila->pedidos);
    free(fila);
}