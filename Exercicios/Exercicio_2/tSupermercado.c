#include "tSupermercado.h"

struct Supermercado
{
    char *nome;
    float estoqueTotal;
    tFilial **filiais;
    int qtdFiliais;
};

tSupermercado *CriaSupermercado()
{
    tSupermercado *supermercado = (tSupermercado *)malloc(sizeof(tSupermercado) * 1);

    printf("Qual o nome do supermercado: ");

    supermercado->nome = LerLinha();

    printf("\n");

    return supermercado;
}

void CriaFiliaisSupermercado(tSupermercado *supermercado)
{
    int qtd;
    char lixo;

    printf("Digite a quantidade de filiais do seu negocio: ");

    scanf("%d%c", &qtd, &lixo);

    supermercado->qtdFiliais = qtd;

    printf("\n");

    supermercado->filiais = CriaFiliais(qtd);

    for (int i = 0; i < qtd; i++)
    {
        ColetaNomeFilial(supermercado->filiais, i);
    }
}

void CalculaEstoqueSupermercado(tSupermercado *supermercado)
{
    supermercado->estoqueTotal = 0;

    supermercado->estoqueTotal += CalculaValorFilial(supermercado->filiais, supermercado->qtdFiliais);
}

void ImprimeSupermercado(tSupermercado *supermercado)
{
    printf("Nome do supermercado: %s, Estoque Total: %.2f\n\n", supermercado->nome, supermercado->estoqueTotal);

    ImprimeFilial(supermercado->filiais, supermercado->qtdFiliais);
}