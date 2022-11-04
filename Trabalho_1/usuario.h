#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hobbies.h"

typedef struct Usuario tUsuario;

tUsuario *CriaUsuario();

tUsuario *ColetaUsuario(FILE *arquivo);

void ImprimeUsuario(tUsuario *usuario);

#endif