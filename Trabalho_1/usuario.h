#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hobbies.h"
#include "arquivo.h"

typedef struct Usuario tUsuario;

tUsuario *CriaUsuario();

tUsuario *ColetaUsuario(FILE *arquivo);

#endif