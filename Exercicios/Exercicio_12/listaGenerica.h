#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ListaGenerica tListaGenerica;

tListaGenerica *CriaListaGenericaVazia();

tListaGenerica *InsereItemListaGenerica(tListaGenerica *lista, void *item);

tListaGenerica *RetiraItemListaGenerica(tListaGenerica *lista, int (*cb)(void*, void*), void *chave);

int PercorreListaGenerica(tListaGenerica *lista, int (*cb)(void *, void *), void *dado);

void LiberaListaGenerica(tListaGenerica *lista);

#endif