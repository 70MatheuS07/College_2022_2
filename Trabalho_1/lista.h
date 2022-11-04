#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include "usuario.h"

typedef struct Lista tLista;

tLista *CriaLista();

tLista *LehUsuariosLista(tLista *lista);

void InsereUsuarioLista(tLista *lista, tUsuario *usuario);

void ImprimeLista(tLista *lista);

#endif