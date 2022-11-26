#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaHobby.h"
#include "listaLike.h"
#include "package.h"
#include "listaPost.h"
#include "listaFeed.h"
#include "listaAmigo.h"

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

char RetornaPrimeiroCharPost(char *post);

int UsuarioAmigoTemLike(tUsuario *usuario, tUsuario *amigoUsuario);

void CriaAmizadeListaAmigoUsuario(tUsuario *usuario, char *nome);

void RetiraAmizadeListaAmigoUsuario(tUsuario *usuario, char *nome);

tListaPost *RetornaListaPostUsuario(tUsuario *usuario);

void EnviaNomeMensagemParaListaFeedUsuarioAmigo(tUsuario *usuario, char *nome, char *mensagem);

tPackage *RetornaPackageUsuario(tUsuario *usuario);

tListaAmigo *RetornaListaAmigoUsuario(tUsuario *usuario);

tListaFeed *RetornaListaFeedUsuario(tUsuario *usuario);

int ConfereUsuariosNomesDiferentes(tUsuario *usuario1, tUsuario *usuario2);

char *RetornaLocalizacaoUsuario(tUsuario *usuario);

int RetornaDiferencaIdadesUsuarios(tUsuario *usuario1, tUsuario *usuario2);

void CriaInsereAmigoListaSugestoes(tUsuario *usuario, char *nome);

tListaAmigo *RetornaListaAmigoSugestoesUsuario(tUsuario *usuario);

int ConfereListaAmigoAmizadeUsuarios(tUsuario *usuario, char *nome);

#endif