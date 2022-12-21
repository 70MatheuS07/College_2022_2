#ifndef LISTAALUNO_H
#define LISTAALUNO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "listaGenerica.h"

typedef struct ListaAluno tListaAluno;

tListaAluno *CriaListaAluno();

tListaAluno *InsereAlunoListaAluno(tListaAluno *lista, tAluno *aluno);

void RetiraAlunoListaAluno(tListaGenerica *lista, int codigo);

void ImprimeListaAluno(tListaGenerica *lista);

void LiberaListaAluno(tListaGenerica *lista);

int ImprimeCB(void *item, void *dado);

#endif