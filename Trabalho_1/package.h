#ifndef PACKAGE_H
#define PACKAGE_H

#define LIKE 1
#define UNLIKE 0

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "like.h"
#include "listaHobby.h"

typedef struct Package tPackage;

tPackage *CriaPackage(int num);

tPackage *LehPackageArquivo(char *nome, tPackage *package, int num);

char *LehCaracterCaracterPackage(FILE *arquivo);

void ImprimePackage(tPackage *package, int num);

char *LehCaracterCaracterPackagePost(FILE *arquivo);

void ColocaStringNoFimDoCharPointer(char *leitura, char *string);

void LiberaPackage(tPackage *package);

tLike *RetornaLikePackage(tPackage *package, int i);

tLike *RetornaUnlikePackage(tPackage *package, int i);

#endif