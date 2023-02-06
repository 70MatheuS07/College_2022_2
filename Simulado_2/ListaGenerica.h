#ifndef LISTA_GENERICA_H
#define LISTA_GENERICA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"

#define ALUNO 0
#define PROFESSOR 1

typedef struct ListaGenerica tListaGenerica;

tListaGenerica *CriaListaGenerica();

void InserePessoaListaGenerica(tListaGenerica *lista, void *pessoa);

#endif