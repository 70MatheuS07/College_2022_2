#ifndef ITENS_H
#define ITENS_H

#include <stdlib.h>
#include <stdio.h>
#include "tProduto.h"

typedef struct Itens tItens;

tItens **CriaItens(int num);

float CalculaValorItens(tItens **itens, int num);

void ImprimeItens(tItens **itens, int num);

#endif
