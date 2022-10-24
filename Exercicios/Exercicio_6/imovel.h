#ifndef IMOVEL_H
#define IMOVEL_H

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "lerLinha.h"

#define IMOVEL 1

typedef struct Imovel tImovel;

tImovel *CriaImovel();

void ImprimeImovel(tImovel *imovel);

#endif