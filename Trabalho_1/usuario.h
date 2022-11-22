#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "like.h"
#include "listaHobby.h"
#include "listaLike.h"
#include "package.h"
//adicao
#include "listaAmigo.h"
#include "listaPost.h"

typedef struct Usuario tUsuario;

tUsuario *CriaUsuario();

tUsuario *ColetaUsuario(FILE *arquivo);

void ImprimeUsuario(tUsuario *usuario, int num, FILE *arquivo);

void LiberaUsuario(tUsuario *usuario);

void LehPackageUsuario(tUsuario *usuario, int num);

char *RegistraLikeUsuario(tUsuario *usuario, int i);

int GerouAmizadeEntreUsuarios(tUsuario *usuarioAmigo, tUsuario *usuario);

char *RetornaNomeUsuario(tUsuario *usuario);

int ConfereSeNomesSaoIguais(tUsuario *usuario, char *nome);

char *RegistraUnlikeUsuario(tUsuario *usuario, int i);

tListaHobby *RetornaListaHobbyUsuario(tUsuario *usuario);

void RegistraListaHobby(tUsuario *usuario, int num, FILE *arquivo);

tListaHobby *ConfereModificaHobbiesEdMatch(tListaHobby *hobbies, tPackage *package, int num);

void RegistraPostUsuario(tUsuario *usuario, int num, FILE *arquivo);

char RetornaPrimeiroCharPost(char *post);

int UsuarioAmigoTemLike(tUsuario *usuario, tUsuario *amigoUsuario);

//adicao
void CriaAmizadeListaAmigoUsuario(tUsuario *usuario, char* nome);

void RetiraAmizadeListaAmigoUsuario(tUsuario *usuario, char* nome);

tListaPost *RetornaListaPostUsuario(tUsuario *usuario);

#endif