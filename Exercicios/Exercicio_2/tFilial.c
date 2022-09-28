#include "tFilial.h"

struct Filial
{
    char *nome;
    tEstoqueFilial *estoque;
};

tFilial *CriaFiliais(int quantidade)
{
    tFilial *filiais = calloc(quantidade, sizeof(tFilial));

    return filiais;
}

void ColetaNomeFilial(tFilial *filial, int num)
{
    printf("Digite o nome da filial %d: ", num + 1);

    filial->nome = lerLinha();

    //PAREI AQUI!!!!!!!!!
}