#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lerLinha.h"
#include "tFilial.h"

typedef struct Supermercado tSupermercado;

tSupermercado *CriaSupermercado();

void CriaFiliaisSupermercado(tSupermercado *supermercado);

void CalculaEstoqueSupermercado(tSupermercado *supermercado);

void ImprimeSupermercado(tSupermercado *supermercado);

void LiberaSupermercado(tSupermercado *supermercado);

#endif
