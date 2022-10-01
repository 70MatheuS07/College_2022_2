#include "tEstoque.h"

struct Estoque
{
    float valor;
    tItens **itensEstoque;
};

tEstoque *CriaEstoque(int num)
{
    int qtd;

    printf("Digite a quantidade de itens diferentes presentes nessa filial %d: ", num + 1);

    scanf("%d", &qtd);

    tEstoque *estoque = calloc(1, sizeof(tEstoque));

    estoque->itensEstoque = CriaItens(qtd);

    return estoque;
}

float CalculaValorEstoque(tEstoque *estoque)
{
    float result=0;
    estoque->valor = 0;

    estoque->valor = CalculaValorItens(estoque->itensEstoque);

    result = estoque->valor;

    return result;
}