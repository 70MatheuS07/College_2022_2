#ifndef ALUNO_H
#define ALUNO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Aluno tAluno;

tAluno *CriaLehAluno(FILE *arquivo);

void ImprimeAluno(tAluno *aluno, FILE *arquivo);

#endif