#include "tItens.h"

struct Itens
{
    int quantidade;
    tProduto *produto;
};

tItens **CriaItens(int num)
{
    int qtd;

    tItens **itens = calloc(num, sizeof(tItens *));

    for (int i = 0; i < num; i++)
    {
        itens[i] = calloc(1, sizeof(tItens));
    }

    for (int i = 0; i < num; i++)
    {
        itens[i]->produto = CriaProduto(i);

        printf("Digite a quantidade do estoque desse produto %d: ", i + 1);
        scanf("%d", &qtd);
        printf("\n");

        itens[i]->quantidade = qtd;
    }

    return itens;
}

float CalculaValorItens(tItens **itens, int num)
{
    float valor = 0;
    float total = 0;
    float result = 0;
    for (int i = 0; i < num; i++)
    {
        valor = PegaValorProduto(itens[i]->produto);
        total = valor * itens[i]->quantidade;
        result += total;
    }

    return result;
}

void ImprimeItens(tItens **itens, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("\tItem: ");

        ImprimeNomeValorProduto(itens[i]->produto);

        printf("quantidade: %d\n", itens[i]->quantidade);
    }
}