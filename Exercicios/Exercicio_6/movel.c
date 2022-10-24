#include "movel.h"

struct Movel
{
    int id;
    float preco;
};

tMovel *CriaMovel()
{
    int id;
    float preco;

    tMovel *movel = malloc(sizeof(tMovel));

    scanf("%d\n", &id);

    scanf("%f\n", &preco);

    movel->id = id;
    movel->preco = preco;

    return movel;
}

void ImprimeMovel(tMovel *movel)
{
    printf("id: %d\n", movel->id);
    printf("preco: %.2f\n", movel->preco);
}