#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "produto.h"

#define CODIGO 1002

int main()
{
    tLista *lista;
    tProduto *produto;

    lista = CriaLista();

    int qtd;
    char lixo;

    scanf("%d", &qtd, &lixo);

    for (int i = 0; i < qtd; i++)
    {
        produto = CriaProduto();
        InsereProdutoLista(lista, produto);
    }

    // Modificar o codigo do produto dependendo do codigo dele
    RetiraProdutoLista(lista, CODIGO);

    ImprimeLista(lista);

    ImprimeListaInvertida(lista);

    LiberaLista(lista);

    return 0;
}