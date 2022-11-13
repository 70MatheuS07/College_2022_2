#ifndef LIKE_H
#define LIKE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Like tLike;

tLike *CriaLike(char *nome, int like);

void LiberaLike(tLike *like);

int EhNomeLikeIgual(tLike *like, char *nome);

void ImprimeLike(tLike *like);

int VerificaLike(tLike *like);

char *RetornaNomeLike(tLike *like);

int ComparaSeNomeLikeIgualNome(tLike *like, char *nome);

void LiberaLikeEdMatch(tLike *like);

#endif