#ifndef TLISTA_H
#define TLISTA_H

#define CACHORRO 0
#define GATO 1

#include <stdlib.h>
#include <stdio.h>
#include "BanhoTosa.h"

typedef struct Lista tLista;

tLista *CriaLista();

void CadastraGatoLista(tLista *animais, Gato *gato);

void CadastraCachorroLista(tLista *animais, Cachorro *cachorro);

void ImprimeLista(tLista *animais);

float CalculaReceitaLista(tLista *animais);

void LiberaLista(tLista *animais);

void BuscaModificaAnimalLista(tLista *animais, Gato *gato);

#endif