#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include "imovel.h"
#include "movel.h"

typedef struct Lista tLista;

tLista *CriaLista();

void RetiraItemDaLista(tLista *lista, int id);

tLista *CriaListaEncadeada(tLista *lista);

void ImprimeLista(tLista *lista);

#endif