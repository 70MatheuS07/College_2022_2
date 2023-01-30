#ifndef TADPALAVRA_H
#define TADPALAVRA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Palavra tPalavra;

tPalavra *InicializaPalavra(char *string);

char *RetornaStringPalavra(tPalavra *palavra);

void AtualizaQuantidadeOcorrencias(tPalavra *palavra);

int RetornaOcorrencias(tPalavra *palavra);

void LiberaPalavra(tPalavra *palavra);

#endif