#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Professor tProfessor;

tProfessor *CriaLehProfessor(FILE *arquivo);

void ImprimeProfessor(tProfessor *professor, FILE *arquivo);

float RetornaFloatPessoa(tProfessor *professor);

#endif