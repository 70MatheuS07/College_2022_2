#ifndef HOBBIES_H
#define HOBBIES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct HobbiesLista tHobbies;

tHobbies *ColetaHobbies(FILE *arquivo);

void InsereHobbyLista(tHobbies *hobbies, char *hobby);

void ImprimeHobbies(tHobbies *hobbies);

#endif