#include "tProduto.h"

struct Produto
{
    char *nome;
    float valor;
};

tProduto *CriaProduto(int i)
{
    float valor;

    tProduto *produto = calloc(1, sizeof(tProduto));

    printf("Digite o nome do produto %d: ", i+1);

    produto->nome = LerLinha();

    printf("Digite o valor desse produto %d: ", i+1);

    scanf("%f", &valor);

    produto->valor = valor;

    return produto;
}