#ifndef TLISTA_H
#define TLISTA_H

#define CACHORRO 0
#define GATO 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BanhoTosa.h"

typedef struct Lista tLista;

tLista *CriaLista();

void CadastraGatoBravoLista(tLista *bravos, Gato *gato);

void CadastraGatoMansoLista(tLista *mansos, Gato *gato);

void CadastraCachorroBravoLista(tLista *bravos, Cachorro *cachorro);

void CadastraCachorroMansoLista(tLista *mansos, Cachorro *cachorro);

void ImprimeLista(tLista *animais);

float CalculaReceitaListaBravos(tLista *bravos);

float CalculaReceitaListaMansos(tLista *mansos);

void LiberaLista(tLista *animais);

void BuscaGatoMansoLista(tLista *animais, Gato *gato);

void InsereGatoMansoLista(tLista *mansos, Gato *gato);

void InsereGatoBravoLista(tLista *bravos, Gato *gato);

void InsereCachorroMansoLista(tLista *mansos, Cachorro *cachorro);

void InsereCachorroBravoLista(tLista *bravos, Cachorro *cachorro);

Gato *RetiraGatoMansoLista(tLista *mansos, Gato *gato);

Gato *RetiraGatoBravoLista(tLista *bravos, Gato *gato);

Cachorro *RetiraCachorroMansoLista(tLista *mansos, Cachorro *cachorro);

Cachorro *RetiraCachorroBravoLista(tLista *bravos, Cachorro *cachorro);

#endif