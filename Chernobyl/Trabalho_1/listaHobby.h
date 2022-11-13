#ifndef LISTAHOBBY_H
#define LISTAHOBBY_H

#include <stdlib.h>
#include <stdio.h>
#include "hobby.h"

typedef struct ListaHobby tListaHobby;

tListaHobby *CriaListaHobby();

tListaHobby *ColetaHobbyLista(FILE *arquivo);

void InsereHobbyLista(tListaHobby *hobbies, char *hobby);

void ImprimeListaHobby(tListaHobby *hobbies);

void LiberaListaHobby(tListaHobby *hobbies);

#endif