#ifndef LISTALIKE_H
#define LISTALIKE_H

#include <stdlib.h>
#include <stdio.h>
#include "like.h"

typedef struct ListaLike tListaLike;

tListaLike *CriaListaLike();

void InsereLikeLista(tListaLike *listaLike, tLike *like);

void RetiraDaListaLike(tListaLike *listaLike, char* nome);

void LiberaListaLike(tListaLike *listaLike);

void ImprimeListaLike(tListaLike *listaLike);

int ComparaListaLikeNome(tListaLike *lista, char *nome);

#endif