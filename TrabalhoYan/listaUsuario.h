#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#include <stdlib.h>
#include <stdio.h>
#include "usuario.h"
#include "package.h"

typedef struct ListaUsuario tListaUsuario;

tListaUsuario *CriaListaUsuario();

tListaUsuario *LehUsuariosLista(tListaUsuario *lista);

void InsereUsuarioLista(tListaUsuario *lista, tUsuario *usuario);

void ImprimeListaUsuario(tListaUsuario *lista, int num);

void LiberaListaUsuario(tListaUsuario *lista);

void LehPackageListaUsuario(tListaUsuario *usuarios, int num);

void ExecutaEdMatch(tListaUsuario *usuarios, int num);

void ConfereAmizadeFeita(tListaUsuario *usuarios, char *nome, tUsuario *usuario, FILE *arquivo);

void ConfereAmizadeDesfeita(tListaUsuario *usuarios, char *nome, tUsuario *usuario, FILE *arquivo);

#endif