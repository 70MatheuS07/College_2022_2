#ifndef LISTAAMIGO_H
#define LISTAAMIGO_H

#include <stdlib.h>
#include <stdio.h>
#include "amigo.h"

typedef struct ListaAmigo tListaAmigo;

tListaAmigo *CriaListaAmigo();

void InsereAmigoLista(tListaAmigo *listaAmigo, tAmigo *amigo);

void LiberaListaAmigo(tListaAmigo *listaAmigo);

void ImprimeListaAmigo(tListaAmigo *listaAmigo);

#endif