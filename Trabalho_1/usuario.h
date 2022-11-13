#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "like.h"
#include "listaHobby.h"
#include "listaLike.h"
#include "package.h"

typedef struct Usuario tUsuario;

tUsuario *CriaUsuario();

tUsuario *ColetaUsuario(FILE *arquivo);

void ImprimeUsuario(tUsuario *usuario);

void LiberaUsuario(tUsuario *usuario);

void LehPackageUsuario(tUsuario *usuario, int num);

char *RegistraLikeUsuario(tUsuario *usuario, int i);

int GerouAmizadeEntreUsuarios(tUsuario *usuarioAmigo, tUsuario *usuario);

char *RetornaNomeUsuario(tUsuario *usuario);

int ConfereSeNomesSaoIguais(tUsuario *usuario, char *nome);

char *RegistraUnlikeUsuario(tUsuario *usuario, int i);

tListaHobby *RetornaListaHobbyUsuario(tUsuario *usuario);

#endif