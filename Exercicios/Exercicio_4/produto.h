#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdlib.h>
#include <stdio.h>
#include "lerLinha.h"

typedef struct Produto tProduto;

tProduto *CriaProduto();

int RetornaCodigoProduto(tProduto *produto);

void LiberaProduto(tProduto *produto);

void ImprimeProduto(tProduto *produto);

#endif