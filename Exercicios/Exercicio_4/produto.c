#include "produto.h"

struct Produto
{
    int codigo;
    char *nome;
    float preco;
};

tProduto *CriaProduto()
{
    tProduto *produto = malloc(sizeof(tProduto));

    char *nome;
    int codigo;
    float preco;

    printf("\nDigite o nome do produto: ");
    nome = LerLinha();

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    printf("\nDigite o preco do produto: ");
    scanf("%f", &preco);

    produto->nome = nome;
    produto->codigo = codigo;
    produto->preco = preco;

    return produto;
}

int RetornaCodigoProduto(tProduto *produto)
{
    int codigo;

    codigo = produto->codigo;

    return codigo;
}

void LiberaProduto(tProduto *produto)
{
    free(produto->nome);
    produto->nome = NULL;

    free(produto);
    produto = NULL;
}

void ImprimeProduto(tProduto *produto)
{
    printf("\n\nProduto: %s\n", produto->nome);
    printf("Codigo: %d\n", produto->codigo);
    printf("Preco: %.2f\n", produto->preco);
}