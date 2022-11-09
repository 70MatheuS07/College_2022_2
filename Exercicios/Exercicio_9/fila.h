#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

typedef struct Fila tFila;

tFila *InicializaFila(int tam);

void InsereLivroFila(tFila *fila, tLivro *livro);

tLivro *RetiraLivroFila(tFila *fila, int num);

void ImprimeFila(tFila *fila, int num);

void LiberaFila(tFila *fila);

#endif