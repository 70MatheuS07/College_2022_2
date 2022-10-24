#include "imovel.h"

struct Imovel
{
    int id;
    char *endereco;
    float preco;
};

tImovel *CriaImovel()
{
    int id;
    float preco;
    tImovel *imovel = malloc(sizeof(tImovel));

    imovel->endereco = LerLinha();

    scanf("%d\n", &id);

    scanf("%f\n", &preco);

    imovel->id = id;
    imovel->preco = preco;

    return imovel;
}

void ImprimeImovel(tImovel *imovel)
{
    printf("id: %d\n", imovel->id);
    printf("endereco: %s\n", imovel->endereco);
    printf("preco: %.2f\n", imovel->preco);
}