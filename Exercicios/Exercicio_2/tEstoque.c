#include "tEstoque.h"

struct Estoque
{
    float valor;
    tItens **itensEstoque;
    int qtdItens;
};

tEstoque *CriaEstoque(int num)
{
    int qtd;

    printf("Digite a quantidade de itens diferentes presentes nessa filial %d: ", num + 1);

    scanf("%d", &qtd);

    tEstoque *estoque = calloc(1, sizeof(tEstoque));

    estoque->qtdItens = qtd;

    estoque->itensEstoque = CriaItens(qtd);

    return estoque;
}

float CalculaValorEstoque(tEstoque *estoque)
{
    float result=0;
    estoque->valor = 0;

    estoque->valor = CalculaValorItens(estoque->itensEstoque, estoque->qtdItens);

    result = estoque->valor;

    return result;
}

void ImprimeEstoque(tEstoque *estoque)
{
    printf("Estoque: %.2f\n", estoque->valor);

    ImprimeItens(estoque->itensEstoque, estoque->qtdItens);
}

void LiberaEstoque(tEstoque *estoque)
{
    LiberaItens(estoque->itensEstoque, estoque->qtdItens);

    free(estoque);
    estoque = NULL;
}