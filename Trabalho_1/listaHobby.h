#ifndef LISTAHOBBY_H
#define LISTAHOBBY_H

#include <stdlib.h>
#include <stdio.h>
#include "hobby.h"

typedef struct ListaHobby tListaHobby;

tListaHobby *ColetaHobbies(FILE *arquivo);

void InsereHobbyLista(tListaHobby *hobbies, char *hobby);

void ImprimeHobbies(tListaHobby *hobbies);

void LiberaHobbies(tListaHobby *hobbies);

#endif