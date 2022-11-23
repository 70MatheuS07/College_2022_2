#ifndef LISTAPOST_H
#define LISTAPOST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "post.h"

typedef struct listaPost tListaPost;

tListaPost* CriaListaPost();

void InsereListaPost(tListaPost* listaPost, tPost* post);

void ImprimeListaPost(tListaPost *listaPost, FILE *arquivo);

void LiberaListaPost(tListaPost* listaPost);

void CriaInserePostNaLista(tListaPost* listaPost, char* msg, int alcance);

#endif
