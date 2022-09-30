#ifndef FILIAL_H
#define FILIAL_H

#include <stdlib.h>
#include <stdio.h>
#include "lerLinha.h"
#include "tEstoque.h"

typedef struct Filial tFilial;

tFilial **CriaFiliais(int quantidade);

void ColetaNomeFilial(tFilial *filial, int num);

void ImprimeFilial(tFilial *filial, int num);

#endif
