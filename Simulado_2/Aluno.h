#ifndef ALUNO_H
#define ALUNO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALUNO 0

typedef struct Aluno tAluno;

tAluno *CriaLehAluno(FILE *arquivo);

#endif