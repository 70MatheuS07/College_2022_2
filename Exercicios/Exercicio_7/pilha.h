#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
#include <stdio.h>
#include "livro.h"

typedef struct Pilha tPilha;

tPilha *CriaPilha(int tamanhoPilha);

void ColocaLivroPilha(tPilha *pilha, tLivro *livro);

tLivro *RetiraLivroPilha(tPilha *pilha);

void ImprimePilha(tPilha *pilha);

#endif