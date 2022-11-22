#ifndef AMIGO_H
#define AMIGO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Amigo tAmigo;

tAmigo *CriaAmigo(char *nome);

void LiberaAmigo(tAmigo *amigo);

int EhNomeAmigoIgual(tAmigo *amigo, char *nome);

void ImprimeAmigo(tAmigo *amigo);

#endif