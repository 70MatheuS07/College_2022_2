#ifndef LISTAHOBBY_H
#define LISTAHOBBY_H

#include <stdlib.h>
#include <stdio.h>
#include "hobby.h"

typedef struct ListaHobby tListaHobby;

tListaHobby *CriaListaHobby();

tListaHobby *ColetaHobbyLista(FILE *arquivo);

void InsereHobbyLista(tListaHobby *hobbies, char *hobby);

void ImprimeListaHobby(tListaHobby *hobbies, FILE *arquivo);

void LiberaListaHobby(tListaHobby *hobbies);

void RetiraDaListaHobby(tListaHobby *listaHobby, char *nome);

int ConfereListaHobbyPackage(tListaHobby *hobby);

void ImprimeHobbiesEdMatch(tListaHobby *hobby, FILE *arquivo);

void LiberaListaHobbyEdMatch(tListaHobby *hobbies);

void CopiaHobbiesPackageParaHobbies(tListaHobby *hobbies, tListaHobby *copia);

char RetornaCharListaHobby(tListaHobby *hobby);

#endif