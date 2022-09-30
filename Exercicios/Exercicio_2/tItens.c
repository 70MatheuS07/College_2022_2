#include "tItens.h"

struct Itens
{
    int quantidade;
    tProduto *produto;
};

tItens *CriaItens(int i)
{
    int qtd;

    tItens *itens = calloc(1, sizeof(tItens));

    itens->produto = CriaProduto(i);

    printf("Digite a quantidade do estoque desse produto %d: ", i+1);
    scanf("%d", &qtd);
    printf("\n");

    itens->quantidade = qtd;

    return itens;
}