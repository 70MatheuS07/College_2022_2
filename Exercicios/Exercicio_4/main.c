#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "produto.h"

int main()
{
    tLista *lista;
    tProduto *produto;

    lista = CriaLista();

    produto = CriaProduto();

    InsereProdutoLista(lista, produto);

    ImprimeLista(lista);

    return 0;
}