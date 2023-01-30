#ifndef TADLISTA_H
#define TADLISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TadPalavra.h"

typedef struct Lista tLista;

tLista *CriaLista();

void InserePalavraLista(tLista *lista, tPalavra *palavra);

tPalavra *BuscaPalavraLista(tLista *lista, char *string);

void ImprimeLista(tLista *lista);

void LiberaLista(tLista *lista);

#endif