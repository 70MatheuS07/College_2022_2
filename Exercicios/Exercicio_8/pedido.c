#include "pedido.h"

struct Pedido
{
    char *nome;
    float valor;
    tLista *produto;
};

tPedido **CriaPedido(int tam)
{
    tPedido **pedidos = malloc(tam * sizeof(tPedido *));

    for (int i = 0; i < tam; i++)
    {
        pedidos[i] = malloc(sizeof(tPedido));
    }

    return pedidos;
}