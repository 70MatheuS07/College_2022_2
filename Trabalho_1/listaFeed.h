#ifndef LISTAFEED_H
#define LISTAFEED_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "feed.h"

typedef struct ListaFeed tListaFeed;

tListaFeed *CriaListaFeed();

void InsereFeedLista(tListaFeed *listaFeed, tFeed *feed);

void LiberaListaFeed(tListaFeed *listaFeed);

void ImprimeListaFeed(tListaFeed *listaFeed, FILE *arquivo);

void ColocaNomeMensagemNaListaFeed(tListaFeed *listaFeed, char *nome, char *mensagem);

#endif