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

tListaAluno *RetiraAlunoListaAluno(tListaAluno *lista, int matricula);

void ImprimeListaAluno(tListaAluno *lista);

void LiberaListaAluno(tListaAluno *lista);

#endif