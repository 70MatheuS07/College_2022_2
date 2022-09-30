#include "tEstoque.h"

struct Estoque
{
    float valor;
    tItens *itensEstoque;
};

tEstoque *CriaEstoque(int num)
{
    int qtd;

    printf("Digite a quantidade de itens diferentes presentes nessa filial %d: ", num + 1);

    scanf("%d", &qtd);

    printf("\n");

    tEstoque *estoque = calloc(qtd, sizeof(tEstoque));

    for (int i = 0; i < qtd; i++)
    {
        estoque[i].itensEstoque = CriaItens(i);
    }

    return estoque;
}