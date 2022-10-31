#ifndef LIVRO_H
#define LIVRO_H

#include <stdlib.h>
#include <stdio.h>
#include "lerLinha.h"

typedef struct Livro tLivro;

tLivro *CriaLivro();

void ImprimeLivro(tLivro *livro);

void LiberaLivro(tLivro *livro);

#endif