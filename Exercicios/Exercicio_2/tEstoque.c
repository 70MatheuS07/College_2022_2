#include "tEstoque.h"

struct EstoqueFilial
{
    float valor;
    tItensEstoque *itensEstoque;
};

struct ItensEstoque
{
    int quantidade;
    tProduto *produto;
};