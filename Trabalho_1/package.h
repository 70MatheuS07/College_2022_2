#ifndef PACKAGE_H
#define PACKAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaLike.h"
#include "listaHobby.h"

typedef struct Package tPackage;

tPackage *CriaPackage();

void LehPackageArquivo(char *nome, tPackage *package, int argc, char *argv[]);

#endif