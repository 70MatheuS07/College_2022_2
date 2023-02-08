#ifndef LISTA_GENERICA_H
#define LISTA_GENERICA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"

typedef struct ListaGenerica tListaGenerica;

tListaGenerica *CriaListaGenerica();

void InserePessoaListaGenerica(tListaGenerica *lista, void *pessoa, void *identificador);

void ImpressaoSelecionadaArquivo(tListaGenerica *lista, int identificador, FILE *arquivo);

float CalculoSelecionado(tListaGenerica *lista, int identificador);

#endif