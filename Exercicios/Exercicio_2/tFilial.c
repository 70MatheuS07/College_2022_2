#include "tFilial.h"

struct Filial
{
    char *nome;
    tEstoque *estoque;
};

tFilial *CriaFiliais(int quantidade)
{
    tFilial **filiais = calloc(quantidade, sizeof(tFilial *));

    return filiais;
}

void ColetaNomeFilial(tFilial *filial, int num)
{
    printf("Digite o nome da filial %d: ", num + 1);

    //Problema aqui na leitura!

    filial[num].nome = LerLinha();

    //filial[num]->estoque = CriaEstoque(num); TIRAR DEPOIS
}

void ImprimeFilial(tFilial *filial, int num)
{
    printf("Filial %d: %s\n", num + 1, filial[num]->nome);
}