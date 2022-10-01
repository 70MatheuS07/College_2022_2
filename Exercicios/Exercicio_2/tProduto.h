#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdlib.h>
#include <stdio.h>
#include "lerLinha.h"

typedef struct Produto tProduto;

tProduto *CriaProduto(int i);

float PegaValorProduto(tProduto *produto);

void ImprimeNomeValorProduto(tProduto *produto);

void LiberaProduto(tProduto *produto);

#endif
