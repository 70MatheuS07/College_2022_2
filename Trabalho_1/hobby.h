#ifndef HOBBY_H
#define HOBBY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Hobby tHobby;

char *ColetaHobbyArquivo(FILE *arquivo);

int EhNomeHobbyIgual(char *hobby, char *nome);

int NaoTemHobbies(tHobby *hobby);

void LiberaHobby(tHobby *hobby);

char *RetornaNomeHobby(tHobby *hobby);

#endif