#ifndef LISTAARV_H
#define LISTAARV_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arvore.h"

typedef struct listaArv ListaArv;

ListaArv *IniciaListaArv();

void InsereListaArv(ListaArv *lista, Arv *arv);

void ImprimeListaArv(ListaArv *lista);

// Arv *RetiraPrimeiraArvDaLista(ListaArv *lista);

void LiberaListaArv(ListaArv *lista);

void PreencheListaArvFrequencia(ListaArv *lista, int V[], int tam);

#endif