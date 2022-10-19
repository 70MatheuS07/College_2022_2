#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

typedef struct Lista tLista;

tLista *CriaLista();

void InsereProdutoLista(tLista *lista, tProduto *produto);

void RetiraProdutoLista(tLista *lista, int codigo);

void ImprimeLista(tLista *lista);

void LiberaLista(tLista *lista);

void ImprimeListaInvertida(tLista *lista);

#endif