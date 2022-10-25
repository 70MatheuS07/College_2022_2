#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include "imovel.h"
#include "movel.h"

typedef struct Lista tLista;

tLista *CriaLista();

tLista *CriaListaEncadeada(tLista *lista);

void ImprimeLista(tLista *lista);

tLista *RetiraLista(tLista *lista, int id);

void LiberaLista(tLista *lista);

void LiberaTodaLista(tLista *lista);

void LiberaListaToda(tLista *lista);

void QualMinhaTaxa(tLista *lista, int id);

#endif