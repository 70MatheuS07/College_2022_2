#ifndef LISTA_H
#define LISTA_H

#include "Arvore.h"
#define NUM_ASCII 256
typedef struct listaArv ListaArv;

ListaArv* IniciaListaArv ();

void InsereListaArv (ListaArv* lista, Arv* arv);

void ImprimeListaArv (ListaArv* lista);

Arv* RetiraPrimeiraArvDaLista (ListaArv* lista);

void LiberaListaArv (ListaArv* lista);

void PreencheListaArvFrequencia(ListaArv* lista, int V[], int tam);

void OrdenaListaArvFrequencia(ListaArv* lista);

int RetornaNumListaArv(ListaArv *lista);

Arv *ExecutaAlgoritimoDeHuffman(ListaArv *lista);

#endif