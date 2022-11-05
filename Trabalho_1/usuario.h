#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaHobby.h"

typedef struct Usuario tUsuario;

tUsuario *CriaUsuario();

tUsuario *ColetaUsuario(FILE *arquivo);

void ImprimeUsuario(tUsuario *usuario);

void LiberaUsuario(tUsuario *usuario);

#endif