#include "tSupermercado.h"

struct Supermercado
{
    char *nome;
    float estoqueTotal;
    tFilial *filiais;
};

tSupermercado *CriaSupermercado()
{
    tSupermercado *supermercado = (tSupermercado *)malloc(sizeof(tSupermercado));

    printf("Qual o nome do supermercado: ");

    supermercado->nome = LerLinha();

    printf("\n");

    return supermercado;
}

void CriaFiliaisSupermercado(tSupermercado *supermercado)
{
    int qtd;

    printf("Digite a quantidade de filiais do seu negocio: ");

    scanf("%d", &qtd);

    supermercado->filiais = CriaFiliais(qtd);

    for (int i = 0; i < qtd; i++)
    {
        ColetaNomeFilial(supermercado->filiais, i);
    }
}