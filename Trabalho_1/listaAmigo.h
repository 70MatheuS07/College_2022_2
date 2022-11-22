#ifndef LISTAAMIGO_H
#define LISTAAMIGO_H

#include <stdlib.h>
#include <stdio.h>
#include "amigo.h"
#include "listaFeed.h"

typedef struct ListaAmigo tListaAmigo;

tListaAmigo *CriaListaAmigo();

void InsereAmigoLista(tListaAmigo *listaAmigo, tAmigo *amigo);

//adicao

void RetiraDaListaAmigo(tListaAmigo *listaAmigo, char* nome);

int NomeNaLista(tListaAmigo *listaAmigo, char* nome);

void CriaInsereAmigoNaLista(tListaAmigo *listaAmigo, char* nome);

int RetornaNumeroDeAmigos(tListaAmigo *listaAmigo);
//

void LiberaListaAmigo(tListaAmigo *listaAmigo);

void ImprimeListaAmigo(tListaAmigo *listaAmigo);

void MandaFeedParaListaAmigo(tListaAmigo *listaAmigo, tListaFeed *listaFeed, char *nome, char *mensagem);

#endif