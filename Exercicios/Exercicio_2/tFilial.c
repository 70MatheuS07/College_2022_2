#include "tFilial.h"

struct Filial
{
    char *nome;
    tEstoque *estoque;
};

tFilial **CriaFiliais(int quantidade)
{
    tFilial **filiais = calloc(quantidade, sizeof(tFilial *));

    for (int i = 0; i < quantidade; i++)
    {
        filiais[i] = calloc(1, sizeof(tFilial));
    }

    return filiais;
}

void ColetaNomeFilial(tFilial **filial, int num)
{
    printf("Digite o nome da filial %d: ", num + 1);

    filial[num]->nome = LerLinha();

    filial[num]->estoque = CriaEstoque(num);
}

float CalculaValorFilial(tFilial **filial, int num)
{
    float estoqueTotalFilial = 0;

    for (int i = 0; i < num; i++)
    {
        estoqueTotalFilial += CalculaValorEstoque(filial[i]->estoque);
    }
}

void ImprimeFilial(tFilial **filial, int num)
{
    printf("Filial %d: %s\n", num + 1, filial[num]->nome);
}