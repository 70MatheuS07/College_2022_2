#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>
#include "pedido.h"
#include "lista.h"
#include "lerLinha.h"

typedef struct Fila tFila;

tFila *CriaFila(int tam);

void InsereFila(tFila *fila, tPedido *pedido);

tLista *RetiraFila(tFila *fila);

void LiberaFila(tFila *fila);

#endif