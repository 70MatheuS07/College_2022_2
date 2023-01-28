#ifndef ARVORE_H
#define ARVORE_H

typedef struct arv Arv;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bitmap.h"

#define TAM_CHAR 8
#define NUM_ASCII 256
#define INICIALIZA_NUM 2

Arv *CriaArv_Vazia(void);

Arv *CriaArv(int frequencia, char caractere);

void Imprime(Arv *a);
// essa função vai servir pra executar o algoritimo de Huffman
Arv *JuntaArvs(Arv *arv_e, Arv *arv_d);

Arv *Libera(Arv *a);

int RetornaFreqArv(Arv *arvore);

int VarreArvore(Arv *a, char caractere, int num, char *palavra);

int CaminhaArvoreRecurssiva(bitmap *mapaBits, Arv *arvore);

int RetornaQtdFolhas(Arv *a);

int arv_vazia(Arv *a);

void TransformaInteiroBinario(int n, int *vet, int id);

void TransformaInteiroBinarioLongLong(long long int n, int *vet, int id);

#endif