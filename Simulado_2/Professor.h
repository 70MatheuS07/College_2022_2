#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PROFESSOR 1

typedef struct Professor tProfessor;

tProfessor *CriaLehProfessor(FILE *arquivo);

#endif