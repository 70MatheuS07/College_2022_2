#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "produto.h"

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

    ImprimeLista(lista);

    //Depende de qual teste o retira produto muda
    //RetiraProdutoLista(lista, 1003);

    LiberaLista(lista);

    return 0;
}