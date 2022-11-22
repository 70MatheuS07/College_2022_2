#ifndef HOBBY_H
#define HOBBY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Hobby tHobby;

tHobby *CriaHobby(char *nome);

char *ColetaHobbyArquivo(FILE *arquivo);

int EhNomeHobbyIgual(char *hobby, char *nome);

int NaoTemHobbies(tHobby *hobby);

void LiberaHobby(tHobby *hobby);

char *RetornaNomeHobby(tHobby *hobby);

char *RetornaNomeHobbyParaCopiaEdMatch(tHobby *hobby);

char RetornaCharHobby(tHobby *hobby);

#endif