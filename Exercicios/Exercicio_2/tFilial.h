#ifndef FILIAL_H
#define FILIAL_H

#include <stdlib.h>
#include <stdio.h>
#include "lerLinha.h"
#include "tEstoque.h"
#define QTD_INICIAL 8

typedef struct Filial tFilial;

tFilial *CriaFiliais(int quantidade);

void ColetaNomeFilial(tFilial *filial, int num);

#endif
