#ifndef LISTAPOST_H
#define LISTAPOST_H

#include "post.h"
typedef struct listaPost tListaPost;

tListaPost* CriaListaPost();

void InsereListaPost(tListaPost* listaPost, tPost* post);

void ImprimeListaPost(tListaPost* listaPost);

void LiberaListaPost(tListaPost* listaPost);

void CriaInserePostNaLista(tListaPost* listaPost, char* msg, int alcance);

#endif
