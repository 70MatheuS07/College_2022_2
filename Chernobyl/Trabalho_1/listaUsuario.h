#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#include <stdlib.h>
#include <stdio.h>
#include "usuario.h"

typedef struct ListaUsuario tListaUsuario;

tListaUsuario *CriaListaUsuario();

tListaUsuario *LehUsuariosLista(tListaUsuario *lista);

void InsereUsuarioLista(tListaUsuario *lista, tUsuario *usuario);

void ImprimeListaUsuario(tListaUsuario *lista);

void LiberaListaUsuario(tListaUsuario *lista);

void LehPackageListaUsuario(tListaUsuario *usuarios, int num);

#endif