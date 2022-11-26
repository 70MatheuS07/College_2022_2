#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#define DIFERENCA_IDADE_MAX 5

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "usuario.h"

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

void MandaFeedParaListaAmigo(tListaUsuario *listaUsuario, tListaAmigo *listaAmigo, char *nome, char *mensagem);

void RegistraPostFeedListaUsuario(tListaUsuario *listaUsuario, tUsuario *usuario, int num, FILE *arquivo);

void RegistraSugestoesAmizadesListaUsuario(tListaUsuario *usuarios);   

#endif