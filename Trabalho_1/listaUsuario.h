#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#include <stdlib.h>
#include <stdio.h>
#include "usuario.h"

typedef struct ListaUsuario tListaUsuario;

tListaUsuario *CriaLista();

tListaUsuario *LehUsuariosLista(tListaUsuario *lista);

void InsereUsuarioLista(tListaUsuario *lista, tUsuario *usuario);

void ImprimeLista(tListaUsuario *lista);

void LiberaLista(tListaUsuario *lista);

void LehPackageListaUsuario(tListaUsuario *usuarios, int argc, char *argv[]);

#endif