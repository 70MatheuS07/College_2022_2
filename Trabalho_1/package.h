#ifndef PACKAGE_H
#define PACKAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaLike.h"
#include "listaHobby.h"

typedef struct Package tPackage;

tPackage *CriaPackage(int num);

tPackage *LehPackageArquivo(char *nome, tPackage *package, int num);

char *LehCaracterCaracterPackage(FILE *arquivo);

void ImprimePackage(tPackage *package, int num);

char *LehCaracterCaracterPackagePost(FILE *arquivo);

#endif