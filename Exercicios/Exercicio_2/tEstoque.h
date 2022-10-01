#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdlib.h>
#include <stdio.h>
#include "tItens.h"
#include "tProduto.h"

typedef struct Estoque tEstoque;

tEstoque *CriaEstoque(int num);

float CalculaValorEstoque(tEstoque *estoque);

#endif
