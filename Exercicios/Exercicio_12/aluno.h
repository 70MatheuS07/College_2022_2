#ifndef ALUNO_H
#define ALUNO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Aluno tAluno;

tAluno *CriaAluno(char*nome, int idade, int matricula);

char *RetornaNomeAluno(tAluno *aluno);

void ImprimeAluno(tAluno *aluno);

void LiberaAluno(tAluno *aluno);

int RetornaMatriculaAluno(tAluno *aluno);

#endif